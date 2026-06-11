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
    int c = a - b - b;
    if(c < 0) c = 0;
    cout << c << endl;
}