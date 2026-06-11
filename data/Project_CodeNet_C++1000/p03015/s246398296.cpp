#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s;
int n;
ll Bigmod(int a,int b)
{
    if(b==0)
        return 1%MOD;
    ll x=Bigmod(a,b/2);
    x=(x*x)%MOD;
    if(b%2==1)
        x=(x*a)%MOD;
    return x;
}

ll recur(int pos)
{
    if(pos==n)
    {
        if(s[pos]=='0')
            return 1ll;
        return 3ll;
    }
    if(s[pos]=='0')
        return recur(pos+1)%MOD;
    else
        return (Bigmod(3,n-pos)+2 * recur(pos+1)%MOD)%MOD;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cin>>s;
    n=s.length()-1;
    cout<<recur(0)<<endl;


    return 0;
}
