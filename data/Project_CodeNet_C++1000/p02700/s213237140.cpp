#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y;
    x = (c+b-1)/b;
    y = (a+d-1)/d;
    if(x <= y){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
