#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e5 + 5;
long long a[NMAX], sol, b[NMAX];
int n;

int main()
{
    cin >> n;
    for(int i = 1; i <= n + 1; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        long long minim = min(a[i], b[i]);
        sol += minim;
        a[i] -= minim;
        b[i] -= minim;
        minim = min(a[i], b[i + 1]);
        sol += minim;
        a[i] -= minim;
        b[i + 1] -= minim;
    }
    cout << sol;
    return 0;
}
