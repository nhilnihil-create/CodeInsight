#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, a, b;
    cin >> k >> a >> b;
    if(a%k == 0 || a-a%k + k <= b){
        cout << "OK" << endl;
    }else{
        cout << "NG" << endl;
    }
}