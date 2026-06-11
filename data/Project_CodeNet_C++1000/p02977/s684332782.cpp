#include<bits/stdc++.h>
#define ll long long
#define pii_ pair<int,int>
#define mp_ make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define show1(a) cout<<#a<<" = "<<a<<endl
#define show2(a,b) cout<<#a<<" = "<<a<<"; "<<#b<<" = "<<b<<endl
using namespace std;
const ll INF = 1LL<<60;
const int inf = 1<<30;
const int maxn = 2e5+5;
inline void fastio() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

int n;
void GG()
{
    cout<<"No"<<endl;exit(0);
}
int main()
{
    fastio();
    cin>>n;
    rep(i,0,30) if((1<<i)==n) GG();
    cout<<"Yes"<<endl;
    rep(i,1,2) cout<<i<<" "<<i+1<<endl;
    cout<<3<<" "<<1+n<<endl;
    rep(i,1,2) cout<<i+n<<" "<<i+1+n<<endl;
    int t = (n&1)?n:n-1;
    for(int i=4;i<=t;i+=2){
        cout<<i<<" "<<1<<endl;
        cout<<i<<" "<<i+1<<endl;
        cout<<i+n+1<<" "<<1<<endl;
        cout<<i+n+1<<" "<<i+n<<endl;
    }
    if(t!=n){
        int a = n-1;
        int b = n^a^1;
        cout<<n<<" "<<a+n<<endl;
        cout<<n+n<<" "<<b<<endl;
    }
    return 0;
}
