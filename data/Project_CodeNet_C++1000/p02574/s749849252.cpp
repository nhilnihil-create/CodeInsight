#include <bits/stdc++.h>

using namespace std;

int MAX = 1e6;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<bool> dp(MAX, false);    
    vector<bool> pr(MAX, true);
    vector<int> D(MAX);
    D[1] = 1;
    for (int i=2; i<MAX; i++) {
        if (pr[i]) {
            D[i] = i;
            for (int j=i; j<MAX/i; j++) {
                D[i*j] = i;
                pr[i*j] = false;
            }
        }
    }
    vector<int> prime;
    int gcd;
    bool ok = false;
    for (int i=0; i<n; i++){
        cin>>a[i];

        if (i == 0) gcd = a[0];
        else gcd = __gcd(gcd, a[i]);

        if (!ok && a[i] > 1) {
            int p = D[a[i]];
            while (p > 1) {
                
                auto it = find(prime.begin(), prime.end(), p);
                if (it == prime.end()) prime.push_back(p);
                else {
                    ok = true;
                    break;
                }
                while (a[i] % p == 0) a[i] /= p;
                p = D[a[i]];
            }
        }
        
    }
    //for (int a : prime) cout << a << " ";
    //cout << '\n';
    if (gcd > 1) cout << "not coprime" << '\n';
    else if (ok) cout << "setwise coprime" << '\n';
    else cout << "pairwise coprime" << '\n';
    return 0;
}