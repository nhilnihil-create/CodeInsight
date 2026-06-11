#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

template <typename T>
class LazySegmentTree{
public:
    enum Operation {
        SUM,
        MAX,
        MIN
    };
    LazySegmentTree(const vector<T>& v, string operation){
        if     (operation == "sum") m_operation = Operation::SUM;
        else if(operation == "max") m_operation = Operation::MAX;
        else if(operation == "min") m_operation = Operation::MIN;
        else{
            cout << "Unknown operation is selected. Abort." <<endl;
            abort();
        }
        m_depth = get_depth(v.size());
        m_N = (1 << m_depth) - 1;
        m_array.resize(m_N);
        m_lazy.resize(m_N, get_dummy_value());

        auto s = get_shift(m_depth - 1);
        // Leaf (within ranges in v)
        for(int i = 0; i < v.size(); i++){
            m_array.at(s + i) = v.at(i);
        }
        // Leaf (out of range)
        for(int i = v.size(); s + i < m_N; i++){
            m_array.at(s + i) = get_dummy_value();
        }
        // Other nodes (calc using child nodes)
        for(int d=m_depth-2; d>=0; d--){
            auto s1 = get_shift(d);
            for(int i=0; i < (1<<d); i++){
                auto child = get_child_index(s1 + i);
                m_array.at(s1 + i) = f(m_array[child[0]], m_array[child[1]]);
            }
        }
    }

    T f(T a, T b){
        if     (m_operation == Operation::SUM) return a + b;
        else if(m_operation == Operation::MAX) return max(a, b);
        else if(m_operation == Operation::MIN) return min(a, b);
        else                                   return 0;
    }
    T f_lazy(T a, int l, int r){
        if     (m_operation == Operation::SUM) return a * (r - l);
        else if(m_operation == Operation::MAX) return a;
        else if(m_operation == Operation::MIN) return a;
        else                                   return 0;
    }
    T f_divide(T a){
        if     (m_operation == Operation::SUM) return a / 2;
        else if(m_operation == Operation::MAX) return a;
        else if(m_operation == Operation::MIN) return a;
        else                                   return 0;
    }
    T get_dummy_value(){
        if     (m_operation == Operation::SUM) return 0;
        else if(m_operation == Operation::MAX) return numeric_limits<T>::min();
        else if(m_operation == Operation::MIN) return numeric_limits<T>::max();
        else                                   return 0;
    }

    void eval(int k, int l, int r){
        if(m_lazy.at(k) == get_dummy_value()) return;

        auto d = m_depth - get_cur_depth(k) - 1; // leaf: d = 0
        m_array.at(k) = f(m_array.at(k), m_lazy.at(k));

        // If not leaf
        if(r - l > 1){
            auto child = get_child_index(k);
            m_lazy.at(child[0]) = f(m_lazy.at(child[0]), f_divide(m_lazy.at(k)));
            m_lazy.at(child[1]) = f(m_lazy.at(child[1]), f_divide(m_lazy.at(k)));
        }

        m_lazy.at(k) = get_dummy_value();
    }

    void update(int i, T x){
        i += get_shift(m_depth - 1);
        m_array.at(i) = x;
        while(i > 0){
            i = get_parent_index(i);
            auto child = get_child_index(i);
            m_array.at(i) = f(m_array[child[0]], m_array[child[1]]);
        }
    }

    void update(int l, int r, T x){
        update(l, r, x, 0, 0, 1 << (m_depth - 1));
    }

    void update(int l, int r, T x, int k, int l2, int r2){
        eval(k, l2, r2);

        if(r <= l2 || r2 <= l) return;

        if(l <= l2 && r2 <= r){
            m_lazy.at(k) = f(m_lazy.at(k), f_lazy(x, l2, r2));
            eval(k, l2, r2);
        }else{
            auto child = get_child_index(k);
            update(l, r, x, child[0], l2, (l2 + r2) / 2);
            update(l, r, x, child[1], (l2 + r2) / 2, r2);
            m_array.at(k) = f(m_array[child[0]], m_array[child[1]]);
        }

    }

    T query(int l, int r){
        return query(l, r, 0, 0, 1 << (m_depth - 1));
    }

    T query(int l, int r, int k, int l2, int r2){
        if (r2 <= l || r <= l2) return get_dummy_value();
        eval(k, l2, r2);
        if (l <= l2 && r2 <= r){
            return m_array[k];
        }else{
            auto child = get_child_index(k);
            auto v1 = query(l, r, child[0], l2, (l2 + r2) / 2);
            auto v2 = query(l, r, child[1], (l2 + r2) / 2, r2);
            return f(v1, v2);
        }
    }

    void print(){
        for(int d=0; d<m_depth; d++){
            auto s = get_shift(d);
            for(int i=0; i < (1<<d); i++){
                cout << m_array.at(s + i) << " ";
            }
            cout << endl;
        }
    }

    void print_lazy(){
        for(int d=0; d<m_depth; d++){
            auto s = get_shift(d);
            for(int i=0; i < (1<<d); i++){
                cout << m_lazy.at(s + i) << " ";
            }
            cout << endl;
        }
    }

private:
    int get_depth(int n){
        int msb = 32 - __builtin_clz(n);
        if(n == 1 << (msb-1)){
            return msb;
        }else{
            return msb + 1;
        }
    }

    // root : 0
    int get_cur_depth(int k){
        return 32 - __builtin_clz(k+1) - 1;
    }

    int get_shift(int d){
        return (1 << d) - 1;
    }

    array<int, 2> get_child_index(int i){
        return array<int, 2>{
            2 * i + 1,
            2 * i + 2,
        };
    }
    int get_parent_index(int i){
        return (i - 1) / 2;
    }

public:
    size_t m_N;
    size_t m_depth;
    Operation m_operation;

    vector<T> m_array;
    vector<T> m_lazy;
};

int main()
{
    ll N, D, A;
    cin >> N >> D >> A;
    vector<array<ll, 2>> inputs(N);
    ll Xi, Hi;
    for(int i=0;i<N;i++){
        cin >> Xi >> Hi;
        inputs[i] = array<ll, 2>{Xi, Hi};
    }
    sort(inputs.begin(), inputs.end());
    vector<ll> X(N);
    vector<ll> H(N);
    for(int i=0;i<N;i++){
        X[i] = inputs[i][0];
        H[i] = inputs[i][1];
    }

    auto sg = LazySegmentTree<ll>(H, "sum");
    ll res = 0;
    for(int i=0;i<N;i++){
        auto v = sg.query(i, i+1);
        if(v <= 0) continue;
        auto n = (v + A - 1) / A;
        res += n;
        auto itr = lower_bound(X.begin(), X.end(), X[i] + 2 * D + 1);
        if(itr == X.end()){
            sg.update(i, N, -A*n);
        }else{
            auto j = distance(X.begin(), itr);
            sg.update(i, j, -A*n);
        }
    }
    cout<<res<<endl;

    return 0;
}
