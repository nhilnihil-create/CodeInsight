#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, c;
    cin >> a >> b >> c;
    c = c - a + b;
    if(c < 0) c = 0;
    cout << c << endl;
    return 0;
}