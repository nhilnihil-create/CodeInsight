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

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n,ans = 0;
    cin>>n;
    int t = n/1000;
    int r = n % 1000;
    if(r>0){
        t+=1;
        ans = t*1000 - n;
    }
    else if(r==0){
        ans = 0;
    }
    cout<<ans<<endl;
    return 0;
}
