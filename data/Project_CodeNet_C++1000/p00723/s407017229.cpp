#include <stdio.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;

void reverse(char str[],int s,int g){
	char tmp;
	for(int i = s;i < s + g - i;i++){
		tmp = str[i];
		str[i] = str[s + g - i];
		str[s + g - i] = tmp;
	}
}

int main(void){
	int i, j, k, l, m, n, sum;
	char str[73], tmp[73];
	scanf("%d%*c",&m);
	for(i = 0;i < m;i++){
		set<string> num;
		gets(str);
		n = strlen(str);
		for(j = 0;j < n - 1;j++){
			for(k = 0;k <= 7;k++){
				strcpy(tmp,str);
				if(1 & k)
					reverse(tmp,0,j); //　上側
				if(2 & k)
					reverse(tmp,j + 1,n - 1); // 下側
				if(4 & k){
					char ttmp[73];
					for(l = 0;l < n;l++)
						ttmp[l] = tmp[(l + j + 1) % n];
					ttmp[n] = '\0';
					strcpy(tmp,ttmp);
				}
				num.insert(tmp);
			}
		}
		printf("%d\n",num.size());
	}
	return 0;
}