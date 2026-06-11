#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define tam 300005

using namespace std;

vi r;
vi c;
vi ic;
vi ir;

bool compr(int a, int b) {
    return r[a] > r[b];
}

bool compc(int a, int b) {
    return c[a] > c[b];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int h, w, m;
    cin >> h >> w >> m;
    int in1, in2;
    r.assign(h + 5, 0);
    c.assign(w + 5, 0);
    ir.assign(h + 5, 0);
    ic.assign(w + 5, 0);
    set <ii> pares;
    for (int i = 0; i < h + 5; i++) ir[i] = i;
    for (int i = 0; i < w + 5; i++) ic[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> in1 >> in2;
        r[in1]++;
        c[in2]++;
        pares.insert({in1, in2});
    }
    sort(ir.begin(), ir.end(), compr);
    sort(ic.begin(), ic.end(), compc);
    while (r[ir.back()] < r[ir[0]]) ir.pop_back();
    while (c[ic.back()] < c[ic[0]]) ic.pop_back();
    for (int i = 0; i < ir.size(); i++) {
        for (int j = 0; j < ic.size(); j++) {
            if (pares.find({ir[i], ic[j]}) == pares.end()) {
                cout << r[ir[0]] + c[ic[0]] << "\n";
                return 0;
            }
        }
    }
    cout << r[ir[0]] + c[ic[0]] - 1 << "\n";
	return 0;
}