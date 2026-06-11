#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main() {
        int x; cin >> x;
        int temp = x / 100;
        if(temp == 0){
            cout << '0' << endl;
            return 0;
        }
        if(x % (temp * 100) <= temp * 5) cout << '1' << endl;
        else cout << '0' << endl;
    return 0;
}
