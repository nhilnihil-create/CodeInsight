#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	char s[101];
	int cnt = 0;
	scanf("%s",s);
	int slen = strlen(s);
	for(int i = 0;i < slen;i++){
		if(s[i] != s[slen - 1 - i]){
			cnt++;
		}
	}
	printf("%d\n",cnt / 2);
}