#include <bits/stdc++.h>

using namespace std;

// template copied from others
namespace __output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T, size_t SZ> void pr(const array<T,SZ>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
 
    template<class T> void pr(const T& x) { cout << x; }
    template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
        pr(first); pr(rest...);
    }
 
    template<class T1, class T2> void pr(const pair<T1,T2>& x) {
        pr("{",x.first,", ",x.second,"}");
    }
    template<class T, bool pretty = true> void prContain(const T& x) {
        if (pretty) pr("{");
        bool fst = 1; for (const auto& a: x) pr(!fst?pretty?", ":" ":"",a), fst = 0;
        if (pretty) pr("}");
    }
    template<class T> void pc(const T& x) { prContain<T, false>(x); pr("\n"); }
    template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
    template<class T> void pr(const vector<T>& x) { prContain(x); }
    template<class T> void pr(const set<T>& x) { prContain(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }
 
    void ps() { pr("\n"); }
    template<class Arg> void ps(const Arg& first) {
        pr(first); ps();
    }
    template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
        pr(first," "); ps(rest...);
    }
}
using namespace __output;

#ifdef DBG
    #define TRACE(x) x
#else
    #define TRACE(x)
#endif

#define p(x) TRACE(pr(x); cout << endl;)
#define __pn(x) pr(#x, " = ")
#define pd(...) TRACE(__pn((__VA_ARGS__)); ps(__VA_ARGS__); cout << flush;)

const int B = 2019;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int N = s.length();

    vector<int> prefix(N);
    for (int i = 0; i < N; ++i) {
        if (i > 0) {
            prefix[i] += (prefix[i - 1] * 10) % B;
        }
        prefix[i] = (prefix[i] + s[i] - '0') % B;
    }

    long long total = 0;

    vector<int> freq(B);
    freq[0] = 1;
    for (int i = 0; i < N; ++i) {
        total += freq[prefix[i]];

        freq[prefix[i]]++;

        vector<int> next_freq(B);
        for (int j = 0; j < B; ++j) {
            next_freq[(j * 10) % B] += freq[j];
        }
        freq = next_freq;
    }

    cout << total << "\n";

    return 0;
}
