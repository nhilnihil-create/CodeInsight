#include <bits/stdc++.h>
using namespace std;

bool check_p(int val);

int main(){
    int X;
    cin >> X;
    
    while(true){
        bool flag = check_p(X);
        if(flag){
            cout << X << endl;
            break;
        }
        X += 1;
    }
    return 0;
}

bool check_p(int val){
    int max_v = int(pow(val, 0.5));
    for(int j=2; j<=max_v; j++){
        if(val%j == 0){
            return false;
        }
    }
    return true;
}