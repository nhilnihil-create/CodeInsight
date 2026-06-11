#include <bits/stdc++.h>
using namespace std;

//1  11  1  11
//2  12  2  12
//3  13  3  0
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= 9;i++){
        if(n % i ==0 && n / i <= 9 && n <82){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}