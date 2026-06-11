#include <iostream>
using namespace std;

int main() {
	long long a,b,c,d;
	cin>>a>>b>>c>>d;
	long long p=a*c;
	long long q=a*d;
	long long r=b*c;
	long long s=b*d;
	cout<<max(p,max(q,max(r,s)));
}
