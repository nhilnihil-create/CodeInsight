#include <bits/stdc++.h>
using namespace std;

int k;

bool f(int a, int b, int c, int x){
    for(int i = 0; i < k; i++){
        int d = x / 3;
        int r = x % 3;
        if(r == 0){
            a *= 2;
        } else if (r == 1){
            b *= 2;
        } else {
            c *= 2;
        }
        x = d;
    }
    return (b > a && c > b);
}

int main(void){
    int a, b, c;
    cin >> a >> b >> c >> k;
    for(int i = 0; i < pow(3, k); i++){
        if(f(a, b, c, i)){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}