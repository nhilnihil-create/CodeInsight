#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
    int n, k;cin >> n >> k;
    vector<int> e(n);
    for(int i = 0;i < n;i++){
        int p;cin >> p;
        e[i] = p + 1;
    }
    ll sum = 0;
    for(int i = 0;i < k;i++)sum += e[i];
    ll m = sum;
    for (int i = k; i < n; i++)
    {
        m = max(m, sum);
        sum = sum + e[i] - e[i-k];
    }
    m = max(sum, m);
    if(m%2 == 0)cout << m/2 << endl;
    else cout << m/2 << ".5" << endl;
    
    return 0;
}