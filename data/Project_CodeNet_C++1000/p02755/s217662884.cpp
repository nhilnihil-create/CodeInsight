// C - Tax increase
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int a, b;
    cin >> a >> b;
    int ans = -1;
    for(int i=1010; i>0; i--){
        int ad=i*0.08, bd=i*0.1;
        if(ad==a && bd==b) ans = i;
        
    }
    cout << ans << endl;
    return 0;
}