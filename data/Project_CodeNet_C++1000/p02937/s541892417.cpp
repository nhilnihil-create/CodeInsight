#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

vector<vector<ll> > num(26);

int main(){
    string s,t;
    cin>>s>>t;
    for(ll i=0;i<s.length();i++){
        int n=(int)(s[i]-'a');
        num[n].push_back(i+1);
    }
    ll ans=0;
    ll pre=0;
    for(ll i=0;i<t.length();i++){
        int n=(int)(t[i]-'a');
        if(num[n].empty()){
            cout<<-1<<endl;
            return 0;
        }else if(upper_bound(num[n].begin(),num[n].end(),pre)==num[n].end()){
            pre=*num[n].begin();
            ans+=s.size();
        }else{
            pre=*upper_bound(num[n].begin(),num[n].end(),pre);
        }
    }
    ans+=pre;
    cout<<ans<<endl;
}