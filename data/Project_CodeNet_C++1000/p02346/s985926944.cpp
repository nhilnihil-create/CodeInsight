#include <bits/stdc++.h>
using namespace std;

template <class type> class SegmentTree{
public:
    int size;
    vector<type> tree;
    type def;
    type (*marge)(type, type);

    SegmentTree(int n, type d, type (*m)(type, type)){
        size = 1;
        def = d;
        marge = m;
        n++;

        while(size < n){
            size *= 2;
        }

        tree.resize(2*size);

        for(int i = 0;i < size;i++){
            tree[size-1+i] = def;
        }

        for(int i = size-2;i >= 0;i--){
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    SegmentTree(int n, type array[], type d, type (*m)(type, type)){
        size = 1;
        def = d;
        marge = m;
        n++;

        while(size < n){
            size *= 2;
        }

        tree.resize(2*size);

        for(int i = 0;i < size;i++){
            if(i < n) tree[size-1+i] = array[i];
            else tree[size-1+i] = def;
        }

        for(int i = size-2;i >= 0;i--){
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    void update(int i, type val){
        i = size-1+i;
        tree[i] = val;

        while(i > 0){
            i = (i-1)/2;
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    void add(int i, type val){
        i = size-1+i;
        tree[i] = tree[i] + val;

        while(i > 0){
            i = (i-1)/2;
            tree[i] = marge(tree[i*2+1], tree[i*2+2]);
        }

        return;
    }

    type get(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return def;
        if(a <= l && r <= b) return tree[k];

        type vl = get(a, b, 2*k+1, l, (l+r)/2);
        type vr = get(a, b, 2*k+2, (l+r)/2, r);

        return marge(vl, vr);
    }

    type get(int a, int b){
        return get(a, b, 0, 0, size);
    }
};

int marge(int a, int b){
    return a + b;
}

int main(){
    int n, q;
    cin >> n >> q;
    SegmentTree<int> tree(n, 0, marge);

    int com, a, b;
    for(int i = 0;i < q;i++){
        cin >> com >> a >> b;
        if(com == 0){
            tree.add(a, b);
        }else{
            cout << tree.get(a, b+1) << endl;
        }
    }

    return 0;
}
