#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){   
    int a ,b; cin >> a >> b;
    for(int n=1;n<=10000;n++){
        int taxa = n*8/100;
        int taxb = n*10/100;
        if(taxa == a && taxb == b){
            cout << n << endl;
            return 0;
        }
    
    }
    cout << -1 << endl;
    return 0;
}
