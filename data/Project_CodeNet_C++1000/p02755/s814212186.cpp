#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
	int a, b;
	cin >> a >> b;

	rep(i, 1100){
		if((floor(i * 0.08) == a) && (floor(i * 0.1) == b)){
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}