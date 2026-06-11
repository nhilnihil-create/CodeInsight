#include <iostream>
#include <string>
#include <vector>

#define mod 1000000000+7;
typedef long long ll;
using namespace std;

vector<int> a,b,c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin >> n;

	for(int i{}; i<n; i++){
		int x; cin >> x;
		a.push_back(x);
	}
	
	for(int i{}; i<n; i++){
		int x; cin >> x;
		b.push_back(x);
	}
		
	for(int i{}; i<n-1; i++){
		int x; cin >> x;
		c.push_back(x);
	}

	int fornor{};
	int extra{};

	for(ll i{0}; i<a.size(); i++){
		fornor+=b[a[i]-1];
		if(i!=0 && a[i]-a[i-1]==1){
			extra+=c[a[i]-2];
		}
	}
	cout << fornor+extra << "\n";
}