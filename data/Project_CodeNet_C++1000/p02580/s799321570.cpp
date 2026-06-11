#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;

int main(){
	int H, W, M; 
	scanf("%d %d %d", &H, &W, &M);
	vector<int> tate(H, 0), yoko(W, 0);
	map<P, int> MAP;
	for(int i = 0; i < M; i++){
		int x, y; scanf("%d %d", &x, &y);
		--x; --y;
		MAP[P(x, y)]++;
		tate[x]++;
		yoko[y]++;
	} 

	auto tate1 = tate, yoko1 = yoko;
    sort(tate.begin(), tate.end(), greater<int>());
	sort(yoko.begin(), yoko.end(), greater<int>());
	int ans = tate[0] + yoko[0];
	int cnt = count(tate.begin(), tate.end(), tate[0]) * count(yoko.begin(), yoko.end(), yoko[0]);
	int cnt1 = 0;

	for(auto key : MAP){
		int x = key.first.first, y = key.first.second;
		if(tate1[x] + yoko1[y] == ans) cnt1++;
	}
	if(cnt == cnt1) ans--;
	printf("%d\n", ans);
}