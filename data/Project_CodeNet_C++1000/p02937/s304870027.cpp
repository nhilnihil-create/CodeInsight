#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl
#define isort(a) sort(a.begin(),a.end())

using namespace std;

#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

typedef pair<ll,ll> Pair;
typedef vector<ll> vecll;
const ll inf =1000000007;


 int main(){
     string s,t;
     cin >> s >>t;
     map<char,vecll> mp;
     for(ll i=0;i<s.size();i++){
         mp[s[i]].pb(i);
     }
     ll ima=-1;
     ll round=0;
     for(ll i=0;i<t.size();i++){
        if(mp[t[i]].empty()){
            cout << -1 << endl;
            return 0;
        }
        else if(upper_bound(mp[t[i]].begin(),mp[t[i]].end(),ima)!=mp[t[i]].end()){
            ima=*upper_bound(mp[t[i]].begin(),mp[t[i]].end(),ima);
        }
        else{
            ima=mp[t[i]][0];
            round++;
        }
     }
     cout << round*s.size()+ima+1LL << endl;
 }
