#include<stdio.h>
using namespace std;

int main(){
	int index,jndex;
	for(index = 1; index <= 9 ; index++){
		for(jndex = 1 ; jndex <= 9 ; jndex++){
			//cout<<index<<"x"<<jndex<<"="<<index*jndex<<endl;
			printf("%dx%d=%d\n",index,jndex,index*jndex);
		}
	}
	
} 