#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	while(cin >> n && n){
		int hs, ms, ss, he, me, se, count[24 * 3600] = {0};
		for(int i = 0; i < n; ++i){
			char c;
			scanf("%d:%d:%d", &hs, &ms, &ss);
			scanf("%d:%d:%d", &he, &me, &se);
			/*scanf("%d%c%d%c%d", hs, c, ms, c, ss);
			scanf("%d%c%d%c%d", he, c, me, c, se);*/
			for(int j = hs * 3600 + ms * 60 + ss; j < he * 3600 + me * 60 + se; ++j){
				count[j]++;
			}
		}
		int ans = 0;
		for(int i = 0; i < 24 * 3600; ++i){
			ans = max(ans, count[i]);
		}
		cout << ans << endl;
	}
	return 0;
}