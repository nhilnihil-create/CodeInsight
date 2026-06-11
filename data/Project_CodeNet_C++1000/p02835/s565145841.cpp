#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if((a+b+c)<=21) cout << "win" << endl;
    if((a+b+c)>=22) cout << "bust" << endl;
}