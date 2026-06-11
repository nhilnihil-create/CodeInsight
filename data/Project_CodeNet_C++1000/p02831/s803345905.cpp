#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e5 + 5;
#define INF 1000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int a[maxn];
int cnt[maxn];

 int getSum(int n) 
    {  
    int sum = 0; 
    while (n != 0) 
    { 
     sum = sum + n % 10; 
     n = n/10; 
    }  
 return sum; 
 }

int countDigit(long long n) 
{ 
    int count = 0; 
    while (n != 0) { 
        n = n / 10; 
        ++count; 
    } 
    return count; 
} 
char S[110];
char T[110];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	ll a,b;
	cin >> a >> b;
	for(int i=1; i<=b; i++){
		if((a*i)%b == 0){
			cout << a*i << "\n";
			break;
		}
	}
	return 0;
}




