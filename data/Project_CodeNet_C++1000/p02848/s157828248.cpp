#include <bits/stdc++.h>
using namespace std;
 
#define oo 1e9
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)
#define _cos(xxxx) cos(xxxx*acos(-1)/180)
#define _sin(xxxx) sin(xxxx*acos(-1)/180)
#define _tan(xxxx) tan(xxxx*acos(-1)/180)
#define PE cout<<fixed
 
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;
 
const ld pi=acos(-1);

ll n,i;
string s;

int main() {
    IO;
    cin>>n;
    cin>>s;
    for (i=0;i<s.length();i++) {
        s[i]=(s[i]-'A'+n)%26+'A';
    }
    cout<<s;
}
    