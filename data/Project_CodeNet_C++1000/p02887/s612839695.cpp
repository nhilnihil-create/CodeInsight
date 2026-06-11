#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
	int n; cin >> n;
	char y ='1';
	string ans ="";
	for(int i=0 ; i < n ; i++){
		char ch ; cin >> ch;
		if(ch!=y)
		ans += ch, y = ch;
	}
	//cout << ans << endl;
	cout << ans.size() << endl;
}