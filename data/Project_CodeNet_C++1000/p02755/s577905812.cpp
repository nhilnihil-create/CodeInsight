#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int tax8,tax10;

    for(int i=1; i<=10000; i++){
        tax8=i*0.08;
        tax10=i*0.1;
        if(a==tax8 && b==tax10){
            cout << i << endl;
            break;
        }
        if(i==10000) cout << -1 << endl;
    }
}