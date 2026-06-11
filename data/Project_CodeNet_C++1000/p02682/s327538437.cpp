#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
	int a,b,c,k;cin>>a>>b>>c>>k;
	int out;
	if(k<=a){
		out =k;
	} else if(k<=a+b){
		out = a;
	} else {
		out = 2*a + b - k;
	}
	cout << out << endl;
  return 0;
}