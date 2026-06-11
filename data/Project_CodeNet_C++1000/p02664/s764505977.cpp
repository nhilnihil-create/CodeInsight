#include <bits/stdc++.h>
using namespace std;

char str[200010];

int main (){
	int i;
	scanf("%s", str);
	for(i = 0; str[i]; ++i) if(str[i] == '?') str[i] = 'D';
	puts(str);
	return 0;
}
