#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define sec second

ll n,m,k,x,x2,y,y2,sol=0,rep,cnt,sad;
char c;
string s;
vector <ll> V;

ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    cin >> k;
    for (int a=1;a<=k;a++){
        for (int b=1;b<=k;b++){
            for (int c=1;c<=k;c++){
                sol+=gcd(gcd(a,b),c);
            }
        }
    }
    cout << sol;
}
