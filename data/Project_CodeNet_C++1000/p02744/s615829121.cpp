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
typedef pair<P,P> PP;
const ll MOD=998244353;
const ll MAX_N=500010;
const ll INF=100100100100100;

int main(){
    int n;
    cin>>n;
    vector< set<string> > ss(n);
    ss[0].insert("a");
    for(int i=0;i<n-1;i++){
        for(string s:ss[i]){
            char maxchar='a';
            for(char c:s) maxchar=max(maxchar, c);
            maxchar++;
            for(char c='a';c<=maxchar; c++){
                ss[i+1].insert(s+c);
            }
        }
    }
    for(string s:ss[n-1]) cout<<s<<endl;
    
}
