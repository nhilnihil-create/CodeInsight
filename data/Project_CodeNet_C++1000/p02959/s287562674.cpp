#include <bits/stdc++.h>

#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define endl '\n'
#define ll long long
#define f first
#define s second
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int main()
{
    IO
    int n;
    cin>>n;
    ll a[n+5],b[n+5],ans=0;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<=b[i]){
           ans+=a[i];
           b[i]-=a[i];
           a[i]=0;
        }
        else {
            ans+=b[i];
            a[i]-=b[i];
            continue;
        }
        if(i+1<=n){
            if(a[i+1]<=b[i]){
                ans+=a[i+1];
                b[i]-=a[i+1];
                a[i+1]=0;
            }
            else {
                ans+=b[i];
                a[i+1]-=b[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}