#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long int
#define mod 1000000007
#define inf 1e18+42
#define endl "\n"
#define pi 3.1415926535897932384626433832795028841971693993751058
#define maxn 100005

#define out1(a) cout<<#a<<" "<<a<<endl
#define out2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define out3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl

#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define fori(it,A) for(auto it=A.begin();it!=A.end();it++)

#define ft first
#define sd second
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define zero(x) memset(x,0,sizeof(x));
#define ceil(a,b) (a+b-1)/b
 
using namespace std;

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//START OF CODE ->->->->->->->

void solve()
{
    int n,k;
    cin>>n>>k;
    vector< pair<int,int> > p;
    if ( k > (n-1)*(n-2)/2 ){
        cout<<"-1"<<endl;
    }
    else{
        rep(i,0,n-1){
            p.pb(mp(1,i+2));
        }
        int x =  - k + (n-1)*(n-2)/2;
        int l = 2;
        int r = 3;
        rep(i,0,x){
            p.pb(mp(l,r));
            if ( r == n ){
                l++;
                r = l+1;
            }
            else{
                r++;
            }
        }

        cout<<p.size()<<endl;
        rep(i,0,p.size()){
            cout<<p[i].ft<<" "<<p[i].sd<<endl;
        }
    }
}

//END OF CODE ->->->->->->->->

signed main()
{
    fast;
    int t = 1;
    // cin>>t;

    while(t--)
    {
        solve();
    }
    return 0;
}

