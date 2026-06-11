#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// C++ program to demonstrate 
// Basic Euclidean Algorithm 
// Function to return  
// gcd of a and b 
ll gcd(ll a, ll b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Dr

int main() {
ll a,b,i,j,count=0;
	a=360;
	cin>>b;
count=gcd(a,b);
j=(a*b)/count;
cout<<j/b;

return 0;
}