#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int ans = -1;
    for (int i = 1; i <= 50000; i++){
        if ((i * 8)/ 100 + i == N){
            ans = i;
        }
    }
    if (ans == -1) cout << ":(" << endl;
    else cout << ans << endl;
}
