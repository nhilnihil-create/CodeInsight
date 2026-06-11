#include <bits/stdc++.h>
using namespace std;

int64_t calc_gcd(int64_t a, int64_t b)
{
    a = a % b;
    if (a == 0)
        return b;
    return calc_gcd(b, a);
}

int64_t calc_lcm(int64_t a, int64_t b)
{
    return a / calc_gcd(a, b) * b;
}

int64_t calc_vec_lcm(const vector<int64_t> &a_vec, int64_t upper)
{
    int64_t lcm = 1;
    for (auto a : a_vec) {
        lcm = calc_lcm(lcm, a);
        if (lcm > upper)
            return upper;
    }
    return lcm;
}
int64_t count_factor2(int64_t a)
{
    int64_t log2 = 0;
    while (a > 0) {
        if (a & 1)
            break;
        ++log2;
        a >>= 1;
    }
    return log2;
}

bool is_feasible(const vector<int64_t> &a_vec)
{
    int64_t cnt, head_cnt = -1;
    int size = a_vec.size();
    head_cnt = count_factor2(a_vec.at(0));
    for (int i = 1; i < size; ++i) {
        cnt = count_factor2(a_vec.at(i));
        if (cnt != head_cnt)
            return false;
    }
    return true;
}

int	main()
{
    int N;
    int64_t M;
    cin >> N >> M;
    vector<int64_t> a_vec(N);
    int64_t a;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        a_vec.at(i) = a / 2;
    }
    if (!is_feasible(a_vec)) {
        cout << 0 << endl;
        return 0;
    }
    int64_t lcm = calc_vec_lcm(a_vec, M + 1);
    cout << M / lcm - M / (2 * lcm) << endl;
}



