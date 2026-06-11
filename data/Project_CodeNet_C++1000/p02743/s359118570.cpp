#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll a,b,c;
	cin>>a>>b>>c;
	if(c-a-b<0||4*a*b>=c*c+a*a+b*b-2*a*c+2*a*b-2*b*c){
		cout << "No";
	}
	else{
		cout << "Yes";
	}
	// your code goes here
	return 0;
}