#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; i++) { 
    	cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    double greater = a[n - 1];

    vector<double> div(n);
    double sum2 = 0;
    for (int i = 0; i < n; i++) {
    	div[i] = greater / a[i];
    	sum2 += div[i];
    }	

    cout << setprecision(12) << greater / sum2 << "\n";

    return 0;
}