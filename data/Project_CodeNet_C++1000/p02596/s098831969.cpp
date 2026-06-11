#include <bits/stdc++.h>
using namespace std;

long long a[1000000+1] = {};

//解説AC
 
int main(){
    int k;
    cin >> k;
    a[0] = 7 % k;
    for(int i = 1; i < k; i++){
        //a[i]は、777...77を示していて、これをkで割っていけば余りを求められることができる。
        a[i] = (a[i-1]*10 + 7) % k;
    }
    //鳩ノ巣原理より、k回調べれば十分となる。
    for(int i = 0; i < k; i++){
        if(a[i] == 0){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}