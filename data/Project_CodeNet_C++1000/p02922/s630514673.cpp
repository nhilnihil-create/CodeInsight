
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int a, b;
    cin >> a >> b;

    if(b==1){
        cout << 0 << endl;
        return 0;
    }

    int ans=0;
    while(true){
        b = b-a+1;
        ans++;
        if(b<=1){
            cout << ans << endl;
            return 0;
        }
    }
}