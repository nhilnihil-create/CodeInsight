#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int64_t a, b, k;
    string ans ="NG";
  
    cin >> k >> a >> b;

    if( a % k == 0 || b % k == 0) ans = "OK";
    if( a / k != b / k) ans = "OK";
    cout <<  ans  << endl;
}