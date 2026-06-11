#include<bits/stdc++.h>
#define ff first
#define ss second
#define len(x) (int)(x.size())
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main(){
	ios::sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	if(b+c>a){
		ans = b+c-a;
	}
	cout << ans << endl;

}
