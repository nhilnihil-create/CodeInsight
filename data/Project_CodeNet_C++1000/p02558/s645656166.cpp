#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(10) <<
#include "atcoder/all"

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)

using namespace std;
using namespace atcoder;


int main(){
    int n, q;
    cin >> n >> q;

    dsu tree(n);
    while(q--){
        int t, u, v;
        cin >>  t >> u >> v;
        if(t){
            if(tree.same(u,v)) cout << 1 << endl;
            else cout << 0 << endl;  
        }else{
            int a = tree.merge(u,v);
        }
    }
}

