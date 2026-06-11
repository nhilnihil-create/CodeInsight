#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=0; i<=n; i++){
        int rest =  n-i*100;
        if(0<= rest && rest <= 5*i){
            cout << "1" << endl;
            return 0;
        }
        if(rest < 0) break;
    }
    cout << "0" << endl;
    return 0;
}