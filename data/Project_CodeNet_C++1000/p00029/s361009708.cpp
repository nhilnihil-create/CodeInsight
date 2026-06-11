#include <iostream>
#include <cstring>
#include <cstdio> //fgets
using namespace std;

int main(){
	char str[1001];
	char word[100][100]={0};
	int longest=0;
	int check[100]={0};
	char *tmp;
	int freq=0;
	int count=0;
	int i,j;
	size_t len , prev;
	fgets(str , sizeof(str) , stdin);
		tmp=str;
		for(i=0 ; str[i]!='\0' ;i++){
			if(str[i]==' '){
				str[i]='\0';
				strcpy((char*)&word[count] , (const char*)tmp);
				tmp=str+i+1;
				count++;
			}
		}
		strcpy((char*)&word[count],(const char*)tmp);
		count++;
	for(i=0 ; i<count ; i++){
		for(j=i ; j<count ; j++){
			if(strcmp((const char*)&word[i] , (const char*)&word[j])==0){
				check[i]++;
			}
		}
	}
	for(i=0 ; i<count-1 ; i++){
		if(check[freq]<check[i+1]){
			freq=i+1;
		}
	}
		prev=strlen(word[0]);
	for (i=1 ; i<count ; i++){
		len=strlen(word[i]);
		if(len > prev){
			prev = len;
			longest=i;
		}
	}
	cout << (char*)&(word[freq]) << " "<< (char*)&(word[longest]) << endl;
	return 0;
}