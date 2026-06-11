#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define for_(i,a,b) for(int i=a;i<b;++i)
#define ALL(a) a.begin(),a.end()
#define INIT(a,b) memset(a,b,sizeof(a))
using lint = long long int;

int main() {
    int N, Q;
    cin >> N >> Q;

    fenwick_tree<lint> fw(N);
    for_(i,0,N) {
        lint a;
        cin >> a;
        fw.add(i, a);
    }
    
    for_(i,0,Q) {
        int t; lint a, b;
        cin >> t >> a >> b;
        if (t == 0) fw.add(a, b);
        else cout << fw.sum(a, b) << endl;
    }
}