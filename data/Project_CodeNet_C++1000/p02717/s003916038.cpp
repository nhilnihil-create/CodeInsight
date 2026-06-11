#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c;
	swap(a,b);
	swap(a,c);
	cout<<a<<" "<<b<<" "<<c;
	return 0;
}