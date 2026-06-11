#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define invrep(i,n) for(int i = n; i > 0; i--)

double dist (int i, int j, vector<int> x, vector<int> y) {
    return pow(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2), 0.5);
}

int main() {
    int n;
    cin >> n;

    vector<int> idx;
    rep(i, n) idx.emplace_back(i+1);

    int p[n], q[n];
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    int p_n, q_n;
    bool p_f = true, q_f = true;
    int cnt = 0;
    do {
        cnt++;
        p_f = true;
        q_f = true;
        for (int i = 0; i < idx.size()-1; i++) {
            if (idx[i] != p[i]) p_f = false;
            if (idx[i] != q[i]) q_f = false;
        }

        if (p_f == true) p_n = cnt;
        if(q_f == true) q_n = cnt;
    } while(next_permutation(idx.begin(), idx.end()));
    
    // cout << cnt << endl;
    cout << abs(p_n - q_n) << endl;
}