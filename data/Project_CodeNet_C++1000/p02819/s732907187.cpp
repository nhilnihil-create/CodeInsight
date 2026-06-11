#include<bits/stdc++.h>
using namespace std;

int is_prime(int x) {
	int root;
	if(x==2) return 1;
	if(x%2==0) return 0;
	root=ceil(sqrt(x));
	for(int i=3;i<=root;i+=2) if(x%i==0) return 0;
		return 1;
}
int main()
{
	int x;
	cin>>x;
	while(1) {
		if(is_prime(x)==1) {cout<<x<<endl;break;}
		x++;
	}
	return 0;
}