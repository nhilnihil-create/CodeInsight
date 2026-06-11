#include<iostream>
using namespace std;
int getPos(int a,int b,int c){
	if(a>=b)return 0;
  	if(b>=c)return 1;
  	return 2;
}	
int main(){
	int A,B,C,K;
  	scanf("%d %d %d",&A,&B,&C);
  	scanf("%d",&K);
  	int pos=0;
  	while((pos=getPos(A,B,C))!=2){
    	if(pos){
        	while(K>0&&B>=C){
            	C*=2;
              	K--;
            }
        }
      	else {
        	while(K>0&&A>=B){
            	B*=2;
              	K--;
            
            }
        }
      if(K==0){
        printf((A<B&&B<C)?"Yes\n":"No\n");
        return 0;
      }
    }
  	printf("Yes\n");
	return 0;
}