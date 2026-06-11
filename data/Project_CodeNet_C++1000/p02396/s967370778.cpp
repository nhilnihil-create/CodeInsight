#include<iostream>
 
int main(void){
 
int x,i;
i=1;
x=1;
while(x!=0){
std::cin>>x;
if(x==0){
break;
}
std::cout<<"Case "<<i<<": "<<x<<std::endl;
i++;
}
 
}