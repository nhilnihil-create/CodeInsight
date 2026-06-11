#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
 
#include <atcoder/dsu>
 
#define ll long long
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589
#define MOD 1000000007
 
using namespace std;
 
template<typename T> T gcd(T a, T b){ return (a % b)? gcd(b, a%b) : b; }
template<typename T> T lcm(T a, T b){ return a * b / gcd(a, b); }
 
int main(void){
    int n, q;
    cin >> n >> q;
    
    atcoder::dsu uf(n);
    REP(i,q){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            uf.merge(u, v);
        } else{
            cout << uf.same(u, v) << endl;
        }
    }
    
    return 0;
}