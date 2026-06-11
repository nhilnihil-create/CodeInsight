#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)



int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int cnt = 0;
    if(a == b)
        cnt++;
    if(b == c)
        cnt++;
    if(c == a)
        cnt++;
    
    if(cnt == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    
    return 0;
}


