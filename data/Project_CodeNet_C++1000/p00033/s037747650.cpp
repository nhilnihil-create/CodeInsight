#include<bits/stdc++.h>

using namespace std;

int ball[11] = {0}, B = 0, C = 0;
int c = 0;
bool solve(int x, int y, int z){
	if(x == 10) return true;
	if(ball[x] > y){
		if(solve(x + 1, y = ball[x], z)) return true;
	}
	if(ball[x] > z){
		if(solve(x + 1, y, z = ball[x])) return true;
	}
	else return false;
}

int main(){
	int N;
	int i, j;
	cin >> N;
	for(i = 0; i < N; ++i){
		for(j = 0; j < 10; ++j) cin >> ball[j];
		if(solve(0, B, C)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}