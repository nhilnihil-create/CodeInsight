#include <bits/stdc++.h>

using namespace std;

int apple[3][100005], need[2], siz[3];

int main() {
	int x, y, a, b, c;
	scanf("%d%d%d%d%d", &need[0], &need[1], &siz[0], &siz[1], &siz[2]);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < siz[i]; j++) {
			scanf("%d", &apple[i][j]);
		}
		
		sort(apple[i], apple[i] + siz[i], greater<int>());
	}
	
	vector <int> choice;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < need[i]; j++) choice.push_back(apple[i][j]);
	}
	
	for (int i = 0; i < siz[2]; i++) choice.push_back(apple[2][i]);
	
	sort(choice.begin(), choice.end(), greater<int>());
	
	long long res = 0;
	
	for (int i = 0; i < need[0] + need[1]; i++) res += choice[i];
	
	printf("%lld\n", res);
}
