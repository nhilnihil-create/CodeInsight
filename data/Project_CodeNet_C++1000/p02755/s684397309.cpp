#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    for(int i=1; i<=1300; i++){
        int tax8 = floor(i * 0.08);
        int tax10 = floor(i * 0.1);
        if(tax8 == a && tax10 == b){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}