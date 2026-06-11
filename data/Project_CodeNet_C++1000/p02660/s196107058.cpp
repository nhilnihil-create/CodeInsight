#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void print() { cout << endl; }
template <typename Head, typename... Tail>
void print(Head head, Tail... tail) {
    int size = sizeof...(Tail);
    cout << head;
    if (size > 0) {
        cout << " ";
    }
    print(tail...);
}

void print0() {}
template <typename Head, typename... Tail>
void print0(Head head, Tail... tail) {
    cout << head;
    print0(tail...);
}

struct xstruct {
    int64_t val;
};
bool operator<=(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val <= rhs.val;
}
bool operator<(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val < rhs.val;
}
bool operator>=(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val >= rhs.val;
}
bool operator>(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val > rhs.val;
}
bool operator==(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val == rhs.val;
}
bool operator!=(const xstruct& lhs, const xstruct& rhs) {
    return lhs.val != rhs.val;
}
ostream& operator<<(ostream& os, xstruct const& xst) {
    return os << xst.val;
}

map<ll, ll> prime_factor(ll n) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (res.count(i) == 0) {
                res[i] = 0;
            }
            res[i]++;
            n = n / i;
        }
    }
    if (n != 1) {
        res[n] = 1;  // n自身が素数
    }
    return res;
}

int main() {
    ll N;
    cin >> N;
    auto pf = prime_factor(N);
    ll result = 0;
    ll right_first = int(sqrt(N) + 1);
    for (auto p : pf) {
        ll prime_num = p.second;

        ll maxused = 0;
        ll right = right_first;
        ll left = 1;
        while (right >= left) {
            ll mid = (right + left) / 2;
            ll total = mid * (mid + 1) / 2;
            if (total <= prime_num) {
                // print(p.first, p.second, total, mid, "middd");
                maxused = max(maxused, mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        // print(p.first, maxused);
        result += maxused;
    }
    cout << result << endl;
}
