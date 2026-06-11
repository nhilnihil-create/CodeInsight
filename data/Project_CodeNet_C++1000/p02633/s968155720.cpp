#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf push_front
#define mp make_pair
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int isprime(int n){
    int count =0;
    for(int i=2;i<=sqrt(n);i++)
    if(n%i==0)count++;
    if(count)return 0;
    return 1;
}
int gcd(int a, int b) 
{ 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
    if (a == b) 
        return a; 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
int main(){
    int x;
    cin>>x;
    int p = x*360/(gcd(x,360));
    cout<<p/x;
    
    return 0;
}



