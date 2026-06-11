#include <bits/stdc++.h>
using namespace std;

int main(){
    int K, A, B;
    cin >> K >> A >> B;
    bool flag = false;

    for(int i = A; i < B+1; i++){
        if(i % K == 0){
            flag = true;
            break;
        }
    }

    if(flag == true){
        cout << "OK" << endl;
    }else{
        cout << "NG" << endl;
    }
}