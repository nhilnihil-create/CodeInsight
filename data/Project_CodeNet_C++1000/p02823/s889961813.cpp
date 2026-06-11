#include<bits/stdc++.h>
#define mod7 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int n, a, b;
	cin>>n>>a>>b;
	if ((b-a)%2 == 0) cout<<(b-a)/2;
	else cout<<(b-a)/2 + min(a, n+1-b);
}

