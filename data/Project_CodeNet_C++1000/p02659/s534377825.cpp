#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <numeric>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <functional>
#include <bitset>
#include <iomanip>
#include <stack>
#include <list>
using namespace std;
#define ll           long long
#define all(v)       (v).begin() , (v).end()
#define vi           vector <ll>
#define vii          vector <pair<ll,ll>>
#define ii           pair<ll,ll>
#define sz(v)	     ((int)((v).size()))
#define lp(i,a,b)    for(int i=a;i<b;i++)
#define pb           push_back
#define pf           push_front
#define F            first
#define S            second
#define endl         "\n"
#define IOS          ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const double PI = 3.14159265358979323846;
const ll inf=2e9,MOD=998244353,MAX=1e7+2;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    ll a;
    string b;
    cin>>a>>b;
    ll x=0,f=0,y=0;
    lp(i,0,sz(b)){
        if(b[i]=='.')
            f=1;
        if(f&&b[i]!='.'){
            y*=10;
            y+=b[i]-'0';
        }
        else if(!f) {
            x*=10;
            x+=b[i]-'0';
        }
    }
    ll z=a*y;
    z/=10;
    z/=10;
    cout<<x*a+z;

}