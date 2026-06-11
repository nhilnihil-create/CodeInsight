#include <bits/stdc++.h>
using namespace std;

int main(){
    long long k=100;
    long long x;
    cin>>x;
    long long i=0;
    while(k<x){
        k+=k/100;
        i++;
    }
    printf("%lld\n",i);

}