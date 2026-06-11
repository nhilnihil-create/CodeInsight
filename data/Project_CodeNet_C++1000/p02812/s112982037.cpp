#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

typedef unsigned long long ull;

const int p = 131;

int N;
char s[60];
ull x,Hash[60],po[60];

int main(){
	scanf("%d",&N);
	scanf("%s",s);
	x='A'*p*p+'B'*p+'C';
	
	Hash[0]=s[0],po[0]=p;
	for(int i=1;i<N;i++){
		Hash[i]=Hash[i-1]*p+s[i];
		po[i]=po[i-1]*p;
	}
	
	int cnt=0;
	for(int i=2;i<N;i++){
		if(Hash[i]-Hash[i-3]*po[2]==x) cnt++;
	}
	printf("%d",cnt);
	return 0;
}
