#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    int m = 0 , h;
    for(int i = 0; i < n; i++){
        cin >> h;
        if(h <= m - 2){
            cout << "No" << endl;
            return 0;
        }
        m = max(m , h);
    }
  
    cout << "Yes" << endl;
}