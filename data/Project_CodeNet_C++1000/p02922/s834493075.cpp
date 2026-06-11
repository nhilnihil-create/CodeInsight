#include <iostream>
#include <string>

#define mod 1000000000+7;
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int a,b; cin >> a >> b;
	int ans{}; int le{1};
	while(le<b){
		--le;
		le += a;
		++ans;
		}
	cout << ans << "\n";
}