#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    int64_t x, ans = 0, a = 100;
    cin >> x;

    while(1){
        ans++;
        a = a + a / 100; 
        if(x <= a)break;
    }

    cout <<  ans  << endl;
}