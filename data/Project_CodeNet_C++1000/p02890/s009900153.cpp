#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Range Minimum/Maximum Query: Semigroup
struct Element{
    ll value;
    bool isIdentity;
};
Element Identity = {0, true};
Element Operation(const Element &A, const Element &B){
    if(A.isIdentity) return B;
    if(B.isIdentity) return A;
    // return {min(A.value, B.value)};
    return {max(A.value, B.value)};
}

struct SegmentTree{
    int size; // number of leaves: power of two
    vector<Element> cbt; // complete binary tree

    // Initialize with Identity Element
    SegmentTree(int N){
        size = 1;
        while (size < N) size *= 2;
        cbt.resize(size * 2 - 1, Identity);
    }

    Element get(int i){
        i += size - 1;
        return cbt[i];
    }

    // Update i-th Leaf (0-indexed) to A
    void update(int i, const Element &A){
        i += size - 1;
        cbt[i] = A;
        while (i > 0){
            i = (i - 1) / 2;
            cbt[i] = Operation(cbt[i*2+1], cbt[i*2+2]);
        }
    }

    // Product of Interval [a, b) (0-indexed)
    Element query(int a, int b) {
        return query_rec(a, b, 0, 0, size);
    }

    Element query_rec(int a, int b, int k, int l, int r){
        // k is root of subtree [l, r)
        if(r <= a || b <= l) return Identity; // outside [a, b)
        if(a <= l && r <= b) return cbt[k]; // interior of [a, b)
        Element vl = query_rec(a, b, k*2+1, l, (l+r)/2);
        Element vr = query_rec(a, b, k*2+2, (l+r)/2, r);
        return Operation(vl, vr);
    }
};

int main() {
    int N;
    cin >> N;
    vector<int>cnt(N+1, 0);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        cnt[A]++;
    }
    sort(cnt.begin(), cnt.end());
    SegmentTree tree(N+1);
    int sum = 0;
    // 取ることのできる回数でループ
    // Kに対して単調減少なので最大のKでセグ木に書き込む
    for (int i = 1; i <= N; ++i) {
        auto iter = lower_bound(cnt.begin(), cnt.end(), i);
        sum += cnt.end() - iter;
        int m = sum / i;
        tree.update(m, {i});
    }
    for (int i = 1; i <= N; ++i) {
        int ans = tree.query(i, N+1).value;
        cout << ans << "\n";
    }
    return 0;
}