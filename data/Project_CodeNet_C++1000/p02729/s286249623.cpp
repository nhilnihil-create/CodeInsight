#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int fact(int n) { 
    int res = 1; 
    for (int i = 2; i <= n; i++) {
        res = res * i;    
    }
    return res; 
}

int nCr(int n, int r) { 
    return fact(n) / (fact(r) * fact(n - r)); 
} 

int main() {
    SPEED;
    int testCases = 1;
    //cin >> testCases;
    while (testCases--) {
        int n,m;
        cin >> n >> m;
        int x = n*(n-1) + m*(m-1);
        cout << x/2 << endl;
    }
    return 0;
}