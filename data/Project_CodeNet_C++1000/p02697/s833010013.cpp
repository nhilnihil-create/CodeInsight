#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, m; cin >> n >> m;

    if(m % 2) {
        for(int i = 0; i < (m + 1) / 2; i++) {
            cout << i + 1 << " " << (m + 1) - i << endl;
        }
        for(int i = 0; i < m - (m + 1) / 2; i++) {
            cout << m + 2 + i << " " << (2*m+1) - i << endl;
        }
    } else {
        for(int i = 0; i < m / 2; i++) {
            cout << i + 1 << " " << m - i  << endl;
        }
        for(int i = 0; i < m - m / 2; i++) {
            cout << m + 1 + i << " " << (2*m+1)-i << endl;
        }
    }
}