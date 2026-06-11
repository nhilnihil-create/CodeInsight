#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    string n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n.size();i++){
        int x = n.at(i) - '0';
        ans += x;
        //printf("%d = %d\n", x, ans);
        ans %= 9;
    }

    if(ans%9 == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}