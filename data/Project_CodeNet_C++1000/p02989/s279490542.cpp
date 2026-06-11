#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<ll> d;

int main(){
    cin >> N;
    d.resize(N);
    for (int i = 0; i < N; ++i) cin >> d[i];
    sort(d.begin(), d.end());
    cout << d[d.size() / 2] - d[d.size() / 2 - 1] << endl;
    return 0;
}