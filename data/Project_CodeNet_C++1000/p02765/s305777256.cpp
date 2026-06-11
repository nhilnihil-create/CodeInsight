#include <bits/stdc++.h>

using namespace std;

int main(){
        int n,r;
        cin >> n >> r;

        if(10 > n){
                cout << r + 100 * (10 - n) << endl;
        }
        else if (n >= 10){
                cout << r << endl;
        }
        return 0;
}