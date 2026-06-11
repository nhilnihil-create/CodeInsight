#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(p,a,b)    for(int p=a;p<b;p++)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define INF 0x3f3f3f3f

int C(int n,int r)
{
    int ans=1;
    if(r>n-r)r = n-r;

    for(int i=0 ; i<r ; i++)
    {
        ans *= ((n-i)/(i+1));
    }

    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k,i,t,ans=0;
    cin>>n>>k;

    if(n)ans=n*(n-1)/2;
    if(k)ans += k*(k-1)/2;
    cout<<ans;
    return 0;
}