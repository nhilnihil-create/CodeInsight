#include <iostream>
#include <cstdio>
int main()
{
	int i=0,num;
	char str[1200],c='a';
	while(c!='\n'){
		scanf("%c",&c);
		str[i]=c;
		i++;
	}
	num=i;
	for(i=0;i<num;i++){
		if(97<=str[i]&&str[i]<=122){
			str[i]=str[i]-32;
		}else if(65<=str[i]&&str[i]<=90){
			str[i]=str[i]+32;
		}
	}
	i=-1;
	while(str[i++]!='\n'){
		if(str[i]=='\n')break;
		std::cout<<str[i];
	}
	std::cout<<std::endl;
	return 0;
}