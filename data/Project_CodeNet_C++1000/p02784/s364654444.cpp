#include <bits/stdc++.h>
using namespace std;
int main(){
        long long int h, n; cin >> h >> n;
        long long int m = 0;
        for (long long int x = 0; x < n; ++x){
            long long int a; cin >> a;
            m += a;
        }
        if (m >= h) cout << "Yes" << endl;
        else cout << "No" << endl;
    return 0;
}
