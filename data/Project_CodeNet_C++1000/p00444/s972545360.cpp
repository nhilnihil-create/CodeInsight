#include<iostream>
using namespace std;
int main(){
	while(1){
	int n;
	cin>>n;
	if(n==0)break;
	int a,b,c,d,e,f,g;
	g=1000-n;
	for(a=0;a<2;a++){
		for(b=0;b<5;b++){
			for(c=0;c<2;c++){
				for(d=0;d<5;d++){
					for(e=0;e<2;e++){
						for(f=0;f<5;f++){
							if(a*500+b*100+c*50+d*10+e*5+f==g){
								cout<<a+b+c+d+e+f<<endl;
								break;
							}
						}
					}
				}
			}
		}
	}
        }
	return 0;
}							
