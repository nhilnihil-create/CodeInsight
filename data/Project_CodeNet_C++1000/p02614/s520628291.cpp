#include <stdlib.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bitset>
#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int h, w, k;
	cin >> h >> w >> k;
	char* c[h];
	rep(i, h) {
		c[i] = (char*)malloc(w * sizeof(char));
		rep(j, w){
			cin >> c[i][j];
		}
	}
	
	int ans = 0;
	rep(hv, 1 << h){
		rep(wv , 1 << w){
			int count = 0;
			rep(i, h)rep(j,w){
				//0なら見ない
				if(!(hv>>i & 1)) continue;
				if(!(wv>>j & 1)) continue;
				if(c[i][j] =='#') count++;
			}
			if(count == k) ans++;
		}
	}
	
	cout << ans << endl;
	
}