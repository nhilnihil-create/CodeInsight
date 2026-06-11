#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

vector<Int> factors(Int n) {
    vector<Int> v;
    for (Int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (i != 1) v.push_back(i);
            if (i*i != n) v.push_back(n/i);
        }
    }
    return v;
}

int main(){ 
    Int N;
    cin >> N;

    
    vector<Int> d1, d2;
    d1 = factors(N);
    d2 = factors(N-1);

    Int cnt1 = 0;

    for (int i = 0; i < d1.size(); ++i) {

        Int M = N;
        Int now = d1[i];
        while (M % now == 0) {
            M /= now;
        }
        if (M % now == 1) cnt1++;
    }

    Int cnt2 = d2.size();


    cout << cnt1 + cnt2 << endl;
}


