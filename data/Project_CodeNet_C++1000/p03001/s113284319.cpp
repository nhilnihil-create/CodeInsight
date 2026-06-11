#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	double w,h,x,y;
	cin >> w >> h >> x >> y;
	cout << w * h / 2 << " ";
	if(w/2==x && h/2==y){
		cout << 1 << endl;
	} else cout << 0 << endl;
	return 0;
}
