#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a, b, c, d;
char s[MAXN];

bool reach(int x, int y){
	while(true){
		if(x > y)return false;
		if(x == y)return true;
		
		if(s[x + 1] == '.'){
			x += 1;
		}else if(s[x + 2] == '.'){
			x += 2;
		}else{
			return false;
		}
	}
}

int main(){
	scanf("%d %d %d %d %d %s", &n, &a, &b, &c, &d, s);
	a--, b--, c--, d--;

	if(!reach(a, c) || !reach(b, d)){
		printf("No\n");
	}else{
		if(c < d){
			printf("Yes\n");
		}else{
			bool found = false;
			for(int i = b; i <= d; i++){
				if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.'){
					found = true;
					break;
				}
			}
			
			if(found)printf("Yes\n");
			else printf("No\n");
		}
	}

	return 0;
}
