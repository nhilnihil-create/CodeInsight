#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#define rep(i,n) for (int i= 0;i<(n);++i)
using namespace std;
typedef long long ll;
int main(){
    ll X ;
    cin >> X ; 
    ll n ;
    n = X / 100 ;
    if(X < 100){
        cout << 0 << endl;
    }else{
        if(5 * n >= (X % 100) )cout << 1 << endl;
        else cout << 0 << endl;

    }
    return 0;
}