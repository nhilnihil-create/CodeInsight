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
#define inf 1e9+7
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl;
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}

typedef pair<ll,ll> Pair;
typedef set<ll> Set;
const ll max_s=1000010;
const ll MOD=1e9+7;

string s;
ll dp1[max_s],dp2[max_s];

void dp(){
    if(s[0]==0){
        dp1[0]=1;
        dp2[0]=0;
    }
    else{
        dp1[0]=2;
        dp2[0]=1;
    }
    for(ll i=1;i<s.size();i++){
        if(s[i]=='0'){
            dp1[i]=dp1[i-1];
            dp2[i]=dp2[i-1]*3;
            dp2[i]%=MOD;
        }
        else{
            dp1[i]=dp1[i-1]*2;
            dp1[i]%=MOD;
            dp2[i]=dp1[i-1]+dp2[i-1]*3;
            dp2[i]%=MOD;
        }
    }
}

int main(){
    cin >> s;
    rep(i,max_s){
        dp1[i]=0;dp2[i]=0;
    }
    dp();
    cout << (dp1[s.size()-1]+dp2[s.size()-1])%MOD << endl;
 
}

