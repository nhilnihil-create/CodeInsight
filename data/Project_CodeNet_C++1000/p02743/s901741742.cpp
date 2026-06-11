#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
 
int main() {
    long long int a, b, c; 
    cin >> a >> b >> c;

    long long int T = (c-a-b)*(c-a-b) - 4*a*b;

    if(c-a-b>0 && T>0 ){
        cout << "Yes" << endl; 
    }
    else{
        cout << "No" << endl;
    } 
}