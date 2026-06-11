#include<iostream>
#include<math.h>
#include<vector>

using namespace std;
char str1[1000000],str2[1000000];

int main(){


cin >> str1 >> str2;
int count = 0;
for(int i=0;str1[i];i++){
	if(str1[i]!=str2[i])count++;
}
printf("%d\n",count);

	return 0;
}