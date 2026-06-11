#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<int> tax(50000, 0);
    for (int i = 1; i <= 50000; i++){
        tax[i] = i + (i * 8) / 100;
    }
    int ans = 0;
    for (int i = 1; i <= 50000; i++){
        if (N == tax[i]) ans = i;
    }
    if (ans == 0) cout << ":(" << endl;
    else cout << ans << endl;
}
