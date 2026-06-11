#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;

const int dir_h[] = {-1, 0, 1, 0};
const int dir_w[] = { 0,-1, 0, 1};

int main(){
	int X, Y;
	cin >> X >> Y;
	int money = 0;
	if(1 == X) money += 300000;
	if(2 == X) money += 200000;
	if(3 == X) money += 100000;
	if(1 == Y) money += 300000;
	if(2 == Y) money += 200000;
	if(3 == Y) money += 100000;
	if(1 == X && 1 == Y) money += 400000;
	cout << money << endl;
	return 0;
}
