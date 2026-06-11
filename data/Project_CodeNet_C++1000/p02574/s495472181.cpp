#include <bits/stdc++.h>
using namespace std;

template<class T> T gcd(T a, T b) {
    return (b ? gcd(b, a % b) : a);
}

const int MAX = 1e6;
vector<int> prime(MAX + 1, -1);

void settable() {
    for(int i = 2; i <= MAX; i++) {
        if(prime[i] == -1) {
            prime[i] = i;
            for(int j = i + i; j <= MAX; j += i) {
                prime[j] = i;
            }
        }
    }
}

int main() {
    settable();
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> ok(MAX + 1, false);
    bool ok1 = true, ok2 = true;
    for(int i = 0; i < n; i++) {
        int nn = a[i];
        if(nn == 1) continue;
        set<int> s;
        do {
            int d = prime[nn];
            s.insert(d);
            nn /= d;
        } while(nn > 1);

        for(auto dd : s) {
            if(ok[dd]) ok1 = false;
            ok[dd] = true;
        }
    }

    int G = 0;
    for(int i = 0; i < n; i++) {
        G = gcd(a[i], G);
    }
    ok2 = (G == 1);
    if(ok1) {
        cout << "pairwise coprime" << endl;
    } else if(ok2) {
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }
    
}