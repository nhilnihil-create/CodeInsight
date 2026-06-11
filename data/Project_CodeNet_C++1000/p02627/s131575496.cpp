#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    char c;
    cin >> c;
    int n = c - 'A';
    if(n <= 25) cout << 'A'<< endl;
    else cout << 'a' << endl;
    return 0;
}