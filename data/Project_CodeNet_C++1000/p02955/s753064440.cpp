#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e6+5;
int a[maxm];
int b[maxm];
int n,k;
int check(int x){
    vector<int>temp;
    for(int i=1;i<=n;i++){
        int t=a[i]%x;
        if(t)temp.push_back(t);
    }
    sort(temp.begin(),temp.end());
    int l=0,r=(int)temp.size()-1;
    int ans=0;
    while(l<r){
        int t=min(temp[l],x-temp[r]);
        ans+=t;
        temp[l]-=t;
        temp[r]+=t;
        if(temp[l]==0)l++;
        if(temp[r]==x)r--;
    }
    return ans<=k;
}
signed main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int sum=0;
    for(int i=1;i<=n;i++)sum+=a[i];
    int ans=0;
    for(int i=1;i*i<=sum;i++){
        if(sum%i==0){
            if(check(i)){
                ans=max(ans,i);
            }
            if(check(sum/i)){
                ans=max(ans,sum/i);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
因为操作不改变序列的总和sum,
因此满足条件的x,一定是sum的因子,
O(sq)枚举sum的因子,然后O(n)check即可.

如何check:
计算出所有a[i]对x的余数t[i]
每个数要么减掉t[i],要么加上x-t[i],
现在要使操作次数最少,且满足加的和减的一样.
*/
