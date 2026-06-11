#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define prtd(var, i) cout << fixed << setprecision(i) << var << endl;
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
   rep(i, 50000){
       if((int)(i * 1.08) == n){
           cout << i << endl;
           return 0;
       }
   }
    cout << ":(" << endl;
}