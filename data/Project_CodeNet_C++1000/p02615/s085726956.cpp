#include<bits/stdc++.h>
using namespace std;
#define Elhabashy ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}
const int N=2e5+5,mod=1e9+7;
typedef long long ll;
int n,arr[N];
ll ans;
int main()
{
    Elhabashy
    input();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+n+1);
    ans=arr[n];
    int cnt=0;
    int idx=n-1;
    for(int i=n-2;i>=1;i--){
        cnt++;
        ans+=arr[idx];
        if(cnt==2){
            cnt=0;
            idx--;
        }
    }
    cout<<ans<<endl;
}
