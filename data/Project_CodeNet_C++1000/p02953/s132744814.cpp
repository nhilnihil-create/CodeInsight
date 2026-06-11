#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 200010
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define F first
#define S second
 
#define ll 	long long int
 
#define mod  1000000007
 
 
int main()
{
	FAST;
	int n;
	cin >> n;
	int a[n+5];
	
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 1; i < n; i ++){
		if(a[i] > a[i-1]){
			a[i] -= 1;
		}
		
	}
	for(int i = 1; i < n; i++){
		if(a[i] < a[i-1]){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}