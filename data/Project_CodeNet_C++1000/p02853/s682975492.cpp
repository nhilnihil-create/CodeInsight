#include <bits/stdc++.h>
using namespace std;
#define forloop(n) for(int i = 0; i < n; i++)
#define ll long long
int main(){
	int n, k; cin>>n>>k;
	cout<<(n < 4 ? 100000 * (4-n) : 0) + (k < 4 ? 100000 * (4-k) : 0) + 400000 * (n == 1 && k == 1);
	return 0;
}