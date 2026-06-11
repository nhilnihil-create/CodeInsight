#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    bool a = true;
    for(int i = 0; i <n ; ++i){
        int temp;
        cin >>temp;
        if(temp%2==0){
            if(temp%3 != 0 && temp%5 != 0){
            a = false;
            }
        }
    }
    if(a){
        cout<<"APPROVED";
    }
    else{
        cout<<"DENIED";
    }
}