#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
private:
    int n;
    vector<int> t;
    
    int combine(int a, int b){
        return a + b;
    }
public:
    SegmentTree(int N){          // build tree
        n = N;
        t.assign(n << 1, 0);
        
        //for (int i = 0; i < n; i++) t[n+i] = v[i];
        //for (int i = n-1; i > 0; i--) t[i] = combine(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, int val){          // set v[p] = val
        for (t[p+=n] += val; p >>= 1; ) t[p] = combine(t[p<<1],t[p<<1|1]);
    }
    int query(int l, int r){              // query in range v[l,r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
            if (l&1) res = combine(res,t[l++]);
            if (r&1) res = combine(res,t[--r]);
        }
        return res;
    }
    int ncquery(int l, int r){            // query for non-commutative combine function
        int resl, resr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1){
            if (l&1) resl = combine(resl, t[l++]);
            if (r&1) resr = combine(t[--r], resr);
        }
        return combine(resl, resr);
    }
};

int N, M;

int main() {

    scanf("%d%d",&N,&M); SegmentTree st(N+1);
    for (int i = 0, op, a, b; i < M; i++) {
        scanf("%d%d%d",&op,&a,&b);

        if (op)
            printf("%d\n", st.query(a,b+1));
        else
            st.modify(a,b);
    }

    return 0;
}