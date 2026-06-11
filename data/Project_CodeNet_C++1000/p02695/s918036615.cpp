#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 + 7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

vector<vector<int>> V;
int N, M, Q;
void gen_seq(int pos, vector<int> v) {
    if (v.back() > 0) {
        V.push_back(v);
    }
    else {
        for (int i = 0; i+v[pos] <= M; i++) {
            v[pos+1] = v[pos]+i;
            gen_seq(pos + 1, v);
        }
    }
}

int main() {
    cin >> N >> M >> Q;
    vector<vector<int>> v(Q);
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        v[i] = { a, b, c, d };
    }
    vector<int> rand(N, 0);
    rand[0] = 1;
    gen_seq(0, rand);
    long long mx = 0;
    for (int i = 0; i < (int)V.size(); i++) {
        long long sum = 0;
        for (int j = 0; j < v.size(); j++) {
            if (V[i][v[j][1]] - V[i][v[j][0]] == v[j][2]) sum += v[j][3];
        }
        mx = max(mx, sum);
    }
    cout << mx;
    
    return 0;
}