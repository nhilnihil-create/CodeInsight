#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
#define ll long long
using namespace std;
int n,k;
int a[200005];
bool check(int x)
{
    int ans = 0;
    for(int i=1; i<=n; ++i){
        ans += (a[i]-1)/x; //偶数4/2 = 2但实际只切了1次，所以减一
    }
    return ans<=k;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    cin>>n>>k;
    int right = 0;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
        right = max(right,a[i]);
    }
    int left = 1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(check(mid)){ //如果ans<=k,则说明次数小，要求最小的最长长度，切割次数要实现最多，需要向k次继续靠近
            right = mid-1;  //那么切割长度应小一些，次数会大一些
        }
        else
            left = mid+1;
    }
    cout<<left<<endl;
    return 0;
}
