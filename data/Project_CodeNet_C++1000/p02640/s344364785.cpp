#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define INF 1000000000
const int maxn = 1e5 + 5;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int countDigit(long long n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	int x,y;
	cin >> x >> y;
	bool ans = 0;
	for(int i=0; i<x+1; i++){
		int cranes = i;
		int turtle = x-i;
		if(cranes*2 + turtle*4 == y){
			ans = 1;
			break;
		}
	}
	cout << (ans?"Yes":"No") << "\n";
}


