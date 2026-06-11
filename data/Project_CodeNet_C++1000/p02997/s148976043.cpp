#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= (n); i++)
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    int c = (n-1)*(n-2)/2-k;
    if(c < 0) cout <<  -1 << endl;
    else{
        cout << c+(n-1) << endl;
        rep(i,n-1) cout << i << " " << n << endl; if(!c) return 0;
        for(int i=1; i<=n-1; i++) for(int j=i+1; j<=n-1; j++){
            cout << i << " " << j << endl;
            c--; if(!c) return 0;
        }
    }
}