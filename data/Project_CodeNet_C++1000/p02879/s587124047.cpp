#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int a, b;
    cin >> a >> b;
    bool ok = true;
    if(a < 1) ok = false;
    if(a > 9) ok = false;
    if(b < 1) ok = false;
    if(b > 9) ok = false;
    if(ok) cout << a*b << endl;
    if(!ok) cout << "-1" << endl;
}