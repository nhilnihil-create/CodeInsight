#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e6 + 5;

int n;
int a[NMAX];
int b[NMAX];
bool am;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        char x; cin >> x;
        a[i] = x - '1';
        if (a[i] == 1)
            am = 1;
        b[a[i]] += (((n - 1) & i) == i);
    }

    if (b[1] % 2 == 1) // imi da impar
        cout << 1;
    else if (!am && (b[2] % 2 == 1)) // nu am 1 si nici n-o sa am
        cout << 2;
    else // am 1
        cout << 0;


    return 0;
}
