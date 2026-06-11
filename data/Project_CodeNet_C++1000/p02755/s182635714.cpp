#include <bits/stdc++.h>
using namespace std;

int main(void){
    int A,B,flag=0;
    cin >> A >> B;
    for(int i=1;i<=1000;i++){
        if(i*8/100==A&&i*10/100==B){
            cout << i;
            flag++;
            break;
        }
    }
    if(!flag){
        cout << -1;
    }
}