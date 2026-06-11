#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define sec second

ll n,m,k,x,x2,y,y2,sol=0,rep,cnt,sad;
char c;
string s;
vector <ll> V;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++){
        if (i%3==0 || i%5==0) continue;
        sol+=i;
    }
    cout << sol;
}
