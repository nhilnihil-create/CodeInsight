#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
private:
    int n;
    vector<int> t;
    
    int combine(int a, int b){
        return a+b;
    }
public:
    SegmentTree(vector<int>& v){                                         // build tree
        n = v.size();
        t.assign(n << 1, 0);
        
        for (int i=0; i<n; i++) t[n+i] = v[i];
        for (int i=n-1; i>0; i--) t[i] = combine(t[i<<1], t[i<<1|1]);
    }
    void modify(int p, int val){                                        // set v[p] = val
        for (t[p+=n]+=val; p>>=1; ) t[p] = combine(t[p<<1],t[p<<1|1]);
    }
    int query(int l, int r){                                            // query in range v[l,r)
        int res = 0;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1){
            if (l&1) res = combine(res,t[l++]);
            if (r&1) res = combine(res,t[--r]);
        }
        return res;
    }
};

int main(){

    ios_base::sync_with_stdio(false);

    /*
     * Input Format (0-base indexing)
     * N = array size
     * Q = number of operation
     */

    // client program for demo

    int N, Q;
    cin >> N >> Q;

    vector<int> v; v.assign(N,0);

    SegmentTree st(v);

    for (int i=0; i<Q; i++){
        int op;
        cin >> op;

        if (op == 0){                       // modify v[p] to val
            int p, val;
            cin >> p >> val; p--;

            st.modify(p,val);
        }
        if (op == 1){                       // query sum of a[l,r]
            int l, r;
            cin >> l >> r; l--; r--;

            cout << st.query(l,r+1) << endl;
        }
    }

    return 0;
}