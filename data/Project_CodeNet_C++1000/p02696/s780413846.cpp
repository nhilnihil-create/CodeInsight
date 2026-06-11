#include<bits/stdc++.h>
using namespace std;
long long a,b,n;
int main() {
	cin>>a>>b>>n;
	cout<<a*min(b-1,n)/b<<endl;
	return 0;
}