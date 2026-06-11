#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x,ans =100;
    int cnt =0;
    cin >>x;
    while(ans<x){
        long long t = ans/100;
        ans += t;
        ++cnt;
    }
    cout << cnt ;
}