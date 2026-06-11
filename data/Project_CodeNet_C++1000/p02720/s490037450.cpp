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
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;

int main(){
    int k;
    cin>>k;
    queue<ll> q;
    for(ll i=1;i<=9;i++) q.push(i);
    ll ans;
    while(k){
        ans=q.front(); q.pop();
        if(ans%10>0) q.push(10*ans+ans%10-1);
        q.push(10*ans+ans%10);
        if(ans%10<9) q.push(10*ans+ans%10+1);
        k--;
    }
    cout<<ans<<endl;
}