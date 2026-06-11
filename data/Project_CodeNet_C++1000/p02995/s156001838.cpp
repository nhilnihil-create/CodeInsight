#include<iostream>
#define ll long long
using namespace std;

ll countDivisibles(ll A, ll B, ll M) 
{ 
    // Add 1 explicitly as A is divisible by M 
    if (A % M == 0) 
        return (B / M) - (A / M) + 1; 
  
    // A is not divisible by M 
    return (B / M) - (A / M); 
} 

ll gcd(ll a, ll b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return a*b/gcd(a,b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << b - a + 1 - countDivisibles(a,b,c) - countDivisibles(a,b,d) + countDivisibles(a,b,lcm(c,d));
	return 0;
}