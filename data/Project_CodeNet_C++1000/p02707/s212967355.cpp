#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){

    int n;
    cin >> n;
    vector<int> t(n, 0);
    int a;

    rep(i, n-1) {
        cin >> a;
        a--;
        t[a]++;
    }
    
    rep(i, n) {
        cout << t[i] << endl;
    }

    return 0;
} 
