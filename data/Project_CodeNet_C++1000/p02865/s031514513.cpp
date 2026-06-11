#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;

int main(){
    ll n; cin>>n;
    if(n%2==0){
        cout<<(n-2)/2<<endl;
    }else{
        cout<<(n-1)/2<<endl;
    }
}