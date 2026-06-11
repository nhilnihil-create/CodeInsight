/* maybemaybemaybeno */
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef long double lld ;
#define f(i,s,n) for(int i=s;i<n;i++) 
// const int MAXN = 2e5+5 ;
#define pb push_back 
#define X first 
#define Y second 
#define pii pair<int,int> 
#define pll pair<ll,ll> 
#define pli pair<ll,int> 
#define pil pair<int,ll> 
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<setprecision(10) ;
#define is(x) cout<<#x<<" : "<<x<<endl ;
// #define DEBUG

int main()
{
    fio ;
    /* ======================Start of code ================ */

    ll A;ll B ;
    cin>>A ;
    string s ;cin>>s ;
    // string s1(1,s[0]) ;
    // string s2(2,s[2]) ;
    string s1 = s.substr(0,1) ;
    string s2 = s.substr(2,4) ;
    #ifdef DEBUG 
    is(s) ;
    is(s1) ;is(s2) ;
    is(s[0]);is(s[1]);is(s[2]) ;is(s[3]) ;
    #endif 
    // B = stoi((string)s[0])*100+((string)(stoi(s[2]+s[3]))) ;
    B = stoi(s1)*100+stoi(s2) ;
    #ifdef DEBUG 
    is(A);is(B) ;
    #endif 
    cout<<(A*B)/100<<"\n" ;
    /* ======================End of code ================== */
}