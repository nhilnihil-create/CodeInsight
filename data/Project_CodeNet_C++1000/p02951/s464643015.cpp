#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int d = b+c;

    if(d>a){
        cout << d-a << endl;
    }else{
        cout << 0 << endl;
    }
}