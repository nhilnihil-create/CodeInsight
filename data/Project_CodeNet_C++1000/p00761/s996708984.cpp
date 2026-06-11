#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int a[22];
char s[10];
int l,j,i;
int memo[22];

int main(){
	while(cin >> s >> l, l){
		i = 0;
		memo[i++] = atoi(s);
		while(strlen(s) != l) strcat(s, "0");
		while(1){
			sort(s, s+l);
			int minnum = atoi(s);
			sort(s, s+l, greater<char>());
			int maxnum = atoi(s);
			memo[i++] = maxnum - minnum;

			sprintf(s, "%d", memo[i-1]);
			while(strlen(s) != l) strcat(s, "0");

			for(j = 0; j < i-1; j++) if(memo[j] == memo[i-1]) break;
			if(j < i-1) break;
		}
		cout << j << ' ' << memo[i-1] << ' ' << i-j-1 << endl;
	}
  return 0;
}