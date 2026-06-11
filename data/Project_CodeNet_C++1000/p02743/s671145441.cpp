#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b,c;
	cin>>a>>b>>c;
	if(c-a-b<0){
		cout << "No";
		return 0;
	}
	ll sum=a*a+b*b+c*c-2*(a*b+b*c+c*a);
	if(sum>0){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}