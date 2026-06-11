#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define ll long long
#define ull unsigned long long
#define dd double
#define oo 1001007000
#define ff float
#define ooo 4223352036854775007
#define iii pair<ll,ll>
#define vii vector<ll>
#define viii vector<iii>
#define sss pair<str,str>
#define str string
#define sii set<ll>
#define siii set<iii>
#define r0 return 0
#define pb push_back
#define sz size
using namespace std;

const char E='\n';
const int N=200005;
const int NN=2005;
const ll md=998244353;

ll _gcd(ll a,ll b){
    while (a>0 && b>0){
        if (a>b)
            swap(a,b);
        b%=a;
    }
    return a+b;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin >> n;
    cout << (n*360/_gcd(n,360))/n << E;
    return 0;
}


/*







*/
