#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
vll div(ll N)
{
    vll yakusuu;
    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            yakusuu.push_back(i);
            if (i * i != N)
                yakusuu.push_back(N / i);
        }
    }
    return yakusuu;
}
int main()
{
    int N, K;
    cin >> N >> K;
    vint A(N);
    ll sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }
    auto divs = div(sum);
    sort(all(divs), greater<ll>());
    for (auto &&i : divs)
    {
        auto tmp = A;
        int num = 0;
        for (size_t j = 0; j < N; j++)
        {
            tmp[j] %= i;
        }
        sort(all(tmp));
        int first = 0, last = N - 1;
        while (first < last)
        {
            int diff = min((ll)tmp[first],i-tmp[last]);
            num += diff;
            tmp[first] -= diff;
            tmp[last] = (tmp[last] + diff)% i;
            if(tmp[first] == 0)
            first++;
            if(tmp[last]==0)
            last--;
        }
        num += min(tmp[first],((int)i-tmp[first]));
        if (num <= K)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}