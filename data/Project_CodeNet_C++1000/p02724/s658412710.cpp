#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int x, a, b;
    cin >> x;
    
    a = x/500;
    b = (x%500)/5;
    
    cout << a*1000 + b*5 << endl;
}
