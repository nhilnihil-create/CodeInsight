#include <bits/stdc++.h>
using namespace std;

#define N 100000
#define K_HAT 3
#define MOD 1000000007

int n; 
int a[N], cntSameHat[N+1];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]++;
    }
    for (int i = 0; i <= n; i++){
        cntSameHat[i] = 0;
    }
    cntSameHat[0] = 3;

    // 
    int ithCombiHat;
    long combi = 1;
    for (int i = 0; i < n; i++){
        cntSameHat[a[i]]++;
        ithCombiHat = cntSameHat[a[i]-1] - cntSameHat[a[i]] + 1;
        combi = combi * ithCombiHat % MOD;
    }

    cout << combi << endl;

    return 0;
}
