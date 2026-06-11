#include <bits/stdc++.h>
using namespace std;

int my_fact(int i) {
    return i ? my_fact(i-1) * i : 1;
}

int my_func(vector<int> a) {
    int result = 0;
    int c_pow = a.size() - 1;

    for (int i = 0; i < a.size(); i++) {
        result += a.at(i) * pow(10, c_pow--);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    int fact_n = my_fact(n);

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p.at(i);
    int p_n = my_func(p);
    vector<int> q(n);
    for (int i = 0; i < n; i++) cin >> q.at(i);
    int q_n = my_func(q);
    
    sort(p.begin(), p.end());

    vector<int> r(fact_n);
    int index = 0;
    do {
        r.at(index++) = my_func(p);
    } while (next_permutation(p.begin(), p.end()));

    int p_i, q_i;
    for (int i = 0; i < fact_n; i++) {
        if (p_n == r.at(i)) p_i = i;
        if (q_n == r.at(i)) q_i = i;
    }

    if (p_i > q_i) {
        cout << p_i - q_i << endl;
    } else {
        cout << q_i - p_i << endl;
    }

    return 0;
}
