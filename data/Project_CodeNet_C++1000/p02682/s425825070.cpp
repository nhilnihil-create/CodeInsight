#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int64_t a, b, c, k, ans;
    cin >> a >> b >> c >> k;
    int64_t n = a + b + c;

    if( k <= a) {
        ans = k;
    }else if( a < k && k <= a + b){
        ans = a;
    }else{
        ans = a + (-1)*(k - a - b);
    }
    cout <<  ans  << endl;
}