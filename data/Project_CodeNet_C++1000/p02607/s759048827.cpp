#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

typedef long long ll;
using namespace std;



bool isPrime(int n){
    if(n < 2){
        return 0;
    }
    if(n%2 == 0){
        return n==2;
    }
    for(int i=3;i*i<=n;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}


int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int h=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]%2 != 0 && (i+1)%2 != 0) h++;
    }
    cout<<h<<endl;
    return 0;
}
