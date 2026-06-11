#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    n =  n % 1000;
    n = 1000 - n;
    if(n==1000) n=0;
    cout << n << endl;
}