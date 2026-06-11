#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int a, b, c, ans=0;
    cin >> a;
    
    b = a/500;
    c = (a - b * 500)/5;
    ans = b * 1000 + c * 5;

    cout <<  ans  << endl;
}