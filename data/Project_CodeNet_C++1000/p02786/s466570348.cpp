#include<bits/stdc++.h>
#define rep(i, n) for(int i=; i<(n); i++)
using ll = long long;
using namespace std;

//  Hより小さい最小の2のべき乗を根とした木を考え、節と葉の数の和が答えとなる。
int main(){
    ll H;
    cin >> H;

    ll cnt=1; 
    int power=0;
    while(true){ // Hより小さい最小の2のべき乗を探す
        cnt = cnt*2; power++;
        if(H < cnt){
            power--;
            break;
        }
    }
    ll res=1;
    for(int i=1; i<=power; i++){
        res += pow(2.0, i);
    }
    cout << res << endl;
}