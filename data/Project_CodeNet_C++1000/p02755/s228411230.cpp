#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    int a, b;
    cin >> a >> b;
    for(int i = 1; i <= 1000; i++){
        if(i*108/100 - i == a && i*110/100 - i == b){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}