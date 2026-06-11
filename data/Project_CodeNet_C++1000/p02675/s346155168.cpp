#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    int n; cin >> n;
    if(n%10 == 3) cout << "bon" << endl;
    else if (n%10 == 0 || n%10 == 1 || n%10 == 6 || n%10 == 8) cout << "pon" << endl;
    else cout << "hon" << endl; 
    return 0;
}