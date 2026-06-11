#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>


#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define vin(v) for (ll i = 0; i < v.size(); ++i) cin >> v[i];
#define vout(v, c) for (int i = 0; i < v.size(); ++i) cout << v[i] << c;

typedef long long ll;
using namespace std;

int main()
{
     ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     int n,k,l,c,d,p,nl,np;
    ll a,b;
    cin>>a>>b;
    if((a+b)%2==0)
        cout<<(a+b)/2;
    else
        cout<<"IMPOSSIBLE";



}
