#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int k,x,i;
	cin>>k>>x;
	i=k*500;
	if(i>=x)cout<<"Yes";
	else cout<<"No";
	return 0;
}
