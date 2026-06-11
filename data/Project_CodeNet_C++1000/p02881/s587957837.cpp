//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

long long printDivisors(long long n) {
	std::vector<long long> v;
	ll mn = 1e18;
    for (ll i=1; i*i<=n; i++)  { 
        if (n%i == 0) { 
            if (n/i == i) {
            	mn = min(mn,(i-1)+(i-1));
            }
            else {
            	ll z = n/i;
            	mn = min(mn,(i-1)+(z-1));
            }
        } 
    } 
    return mn;
} 

int main(){
	
	long long n;
	cin>>n;

	ll x=  printDivisors(n);
	cout<<x<<endl;

	

	return 0;
}