#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=1;i<=(n);i++)
typedef long long ll;

int main() {
    int a,b;
    cin >> a >> b;
    int ans = -1;
    for(int i=1500;i>=0;i--){
        int a_tax=i*0.08;
        int b_tax=i*0.1;
        if(a_tax==a&&b_tax==b) ans = i;
    }
    cout << ans << endl;
}