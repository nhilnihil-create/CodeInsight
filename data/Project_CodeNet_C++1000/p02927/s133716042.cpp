#include<bits/stdc++.h>
using namespace std;

int main(void){
    int m,a,b,d,count = 0;
    cin >> m >> d;
    for(int i = 1;i <= m;i++){
        for(int j = 22;j <= d;j++){
            a = j % 10;
            b = j / 10;
            if(a * b == i && a >= 2)count++;
        }
    }
    cout << count;
}