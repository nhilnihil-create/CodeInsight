#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    multiset<int> S, T;
    rep(i, 1<<n){
        int a;
        scanf("%d", &a);
        S.insert(a);
    }
    
    T.insert(*S.rbegin());
    S.erase(--(S.end()));
    vector<int> v;
    while(!S.empty()){
        for(auto t=T.begin(); t!=T.end(); ++t){
            auto s = S.lower_bound(*t);
            if(s == S.begin()){
                printf("No\n");
                return 0;
            }
            --s;
            v.push_back(*s);
            S.erase(s);
        }
        for(int x: v) T.insert(x);
        v.clear();
    }
    printf("Yes\n");
}