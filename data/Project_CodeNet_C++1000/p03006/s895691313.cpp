#include <bits/stdc++.h>
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    map<pii, int> cnts;
 
    for(int i=0; i<n; i++) {
        map<pii, int> temp;
        for(int j = 0; j < n; j++) {
            pii tmp = pii(x[i]-x[j], y[i]-y[j]);
            if(i != j) temp[tmp]++;
        }
        for(auto& p: temp) {
            cnts[p.first]++;
        }
    }
 
    int mx = 0;
    for(auto& p: cnts) {
        mx = max(mx, p.S);
    }
 
    cout << n - mx << endl;
    return 0;
}