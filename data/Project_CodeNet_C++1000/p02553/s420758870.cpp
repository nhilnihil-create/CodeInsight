#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
	ll a,b,c,d;
	ll q[4]; 
	cin>>a>>b>>c>>d;
	q[0]=a*c;q[1]=a*d;q[2]=b*c;q[3]=b*d;
	sort(q,q+4);
	cout<<q[3];
	return 0;
}