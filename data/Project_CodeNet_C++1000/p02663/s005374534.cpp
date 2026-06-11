#include<bits/stdc++.h>
using namespace std;
int main(void){
    int hx, mx, hy, my, k;
    cin >> hx >> mx >> hy >> my >> k;
    mx += hx * 60; my += hy * 60;
    cout << my - mx  - k << endl;
    return 0; 
}