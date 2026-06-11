#include <bits/stdc++.h>
using namespace std;
#define forloop(n) for(int i = 0; i < n; i++)
#define ll long long

int main(){
	int n; cin>>n;
	cout<<(n % 2 ? (n+1)/2 - 1 : n/2 - 1);
	return 0;
}