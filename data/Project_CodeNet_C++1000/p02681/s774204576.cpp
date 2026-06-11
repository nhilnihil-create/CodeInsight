#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[110],t[110];
int main(){
	scanf("%s%s",s+1,t+1);
	bool mk=true;
	for(int i=1;i<=strlen(s+1);++i)if(s[i]!=t[i]){
		mk=false;
		break;
	}
	cout<<(mk ? "Yes" : "No")<<endl;
	return 0;
}


