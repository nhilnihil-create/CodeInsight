#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define sol (k+k)
#define sag (k+k+1)
#define orta ((bas+son)/2)
#define ort ((bas+son+1ll)/2ll)
#define coc g[node][i]
#define mod 1000000007
#define inf 1000000009
#define N 1000005
using namespace std;
 
typedef long long ll;
typedef pair < int , int > ii;

long long n;

int main() {
	
	cin >> n;
	
	if(n % 2 == 0)
	 cout << n/2-1;
	else
	 cout << (n-1) / 2;
	 
	
	return 0;
}
