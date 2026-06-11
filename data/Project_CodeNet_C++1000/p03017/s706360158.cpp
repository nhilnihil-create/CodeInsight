#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, a, b, c, d;
char field[200005];

int main(){
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	scanf(" %s", field + 1);
	bool overtake = false;
	while(b < d){
		// check this cell
		if(field[b - 1] == '.' && field[b + 1] == '.'){
			overtake = true;
		}
		if(field[b + 1] == '.'){
			b++;
		}else if(b + 2 <= d && field[b + 2] == '.'){
			b += 2;
		}else{
			printf("No\n");
			return 0;
		}
	}
	if(field[b - 1] == '.' && field[b + 1] == '.'){
		overtake = true;
	}
	
	if(c > d && !overtake){
		printf("No\n");
		return 0;
	}
	while(a < c){
		if(field[a + 1] == '.'){
			a++;
		}else if(a + 2 <= c && field[a + 2] == '.'){
			a += 2;
		}else{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}
