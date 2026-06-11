#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ll a,b,k;
	cin>>a>>b>>k;
	if(k<=a){
		cout<<a-k<<" "<<b;;
	}else if(k<=a+b){
		cout<< 0 <<' '<<b- (k-a) <<endl;
	}else{
		cout<<0<<" "<<0;
	}

   return 0;
}
