#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

typedef pair <int,int> pii;
typedef vector <pii> vpii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int lli;
typedef vector <lli> vlli;
typedef vector <vlli> vvlli;
typedef vector <string> vs;
typedef vector <bool> vb;

#define rep(i, n) for( i = 0; i < (n); ++i)
#define repA(i, a, n) for( i = a; i <= (n); ++i)
#define repD(i, a, n) for( i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sortr(x) sort(x.begin(),x.end(),greater <int> ())
#define mod 1000000007
#define ff first
#define ss second
#define fill(a,c)  memset(a, c, sizeof (a))
#define formap(i,v) for(auto &i: v)
#define dbg(x) cout << #x << " = " << x << '\n'
#define dbg2(x,y) cout<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl(v) cout<<#v<<" = \n"; { int c=0; formap(it,v) \
cout<<"    "<<#v<<"["<< ++c <<"] = "<<it<<endl;} cerr<<endl
#define dbgstlp(v) cout<<#v<<" = \n"; { int c=0; formap(it,v) \
cout<<"    "<<#v<<"["<< ++c <<"] = "<<it.first<<" , "<<it.second<<endl;} cerr<<endl
#define PI  3.14159265358979323846
#define pb push_back




int main() {
     cin.sync_with_stdio(0);cin.tie(0);
     cin.exceptions(cin.failbit);
    
    
    int i,j,n,k,ans,b,val;
    cin>>n;
    k= n/100; val=n%100;
    if (val>k*5)ans=0;
    else ans=1;
    cout<<ans<<endl;
    
     
     
     
     
     
     
     
     
     
   
   
	return 0;
}
