#include <bits/stdc++.h>
using namespace std;
typedef long double ll;

ll N;
vector<ll> v;

int main() { 
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll out = v[0];
    for (int i = 1; i < N; i++){
      out = (out + v[i]) / 2;
    }
    cout <<fixed << setprecision(5) << out << endl;
    return 0;
}