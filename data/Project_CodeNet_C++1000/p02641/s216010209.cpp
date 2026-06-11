#include<bits/stdc++.h>
using namespace std;

bool cek[102];

int main(){
	int x,n;
	cin >> x >> n;
	while(n--){
		int y;
		cin >> y;
		cek[y] = 1;
	}
	int up = x,down=x;
	if(!cek[x]){
		cout << x << '\n';
	}else{
		int ans=-1;
		down = x;
		up = x;
		while(cek[down]&&cek[up]){
			down--;
			up++;
			if(!cek[down]){
				ans = down;
			}else if(!cek[up]){
				ans = up;
			}
		}
		cout << ans << '\n';
	}
}