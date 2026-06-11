#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define fi first
#define se second
#define endl "\n"
#define all(v) v.begin(),v.end()
#define fastio ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define go_t int t;cin>>t;for(int tt=1;tt<=t;tt++)
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define trace2(x, y)         cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<< endl;
#define trace3(x, y, z)      cout <<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl;
#define trace4(a, b, c, d)   cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;
#define trace5(a, b, c, d, e)cout <<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<<": "<<e<<endl;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf = 0x3f3f3f3f3f3f3f3fll;//4x10e18
const int N = 300000 , mod = 1000000007;
int main()
{
    fastio;
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int cnt = 0;
    while(100)
    {
        int temp[n+2];
        set_ar(temp,0);
        for(int i=1;i<=n;i++)
        {
            int sta = max(i - a[i],1);
            int en = min(n,i+a[i]);
            temp[sta]+=1;
            temp[en+1]-=1;
        }
        for(int i=1;i<=n;i++)
        {
            temp[i]+=temp[i-1];
            a[i] = temp[i];
        }
        cnt++;
        int mn = *min_element(a+1,a+n+1);
        if(mn==n || cnt==k)break;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}