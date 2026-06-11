
//don't go gentle into
// the goodnight.

#include<bits/stdc++.h>
using namespace std;

#define int       long long
#define ll        long long
#define fr        first
#define sec       second
#define pi        3.141592653589793
#define M         1000000007
#define mod       998244353
#define maxint    2147483647
#define minint    -2147483648
#define maxll     9223372036854775807
#define minll     -9223372036854775808
#define meme0(a)  memset(a,0,sizeof(a));
#define meme1(a)  memset(a,-1,sizeof(a));
#define i_m_speed ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define open      freopen("input.txt","r",stdin);
#define close     freopen("output.txt","w",stdout);
#define v_int     vector<int >
#define v_ll      vector<long long >
#define pb        push_back
#define mk        make_pair
//upper_bound(begin(),end(),key)
//lower_bound(begin(),.end(),key);

ll expo(ll x , ll n , ll m){
    if(n==0)
        return 1;
    else if(n%2==0)
        return expo((x*x)%m , n/2 , m);
    else
        return (x*expo((x*x)%m,(n-1)/2,m))%m;

}
string toBinary(ll n)
{
    std::string r;
    while(n!=0){
        r=(n%2==0 ?"0":"1")+r;
        n/=2;
    }
    return r;
}


void solve(){
    string s,t;
    cin >> s >> t;
    int a,b;
    cin >>a >> b;
    string u;
    cin >> u;
    if(u==s)
         cout << a-1 << " " << b << endl;
     else if(u==t)
            cout << a << " "  << b-1  << endl;
    else cout << a<< " " << b << endl;

    return;
}
int32_t main(){
    i_m_speed
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
