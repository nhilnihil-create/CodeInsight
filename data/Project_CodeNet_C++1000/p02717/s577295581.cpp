#include<iostream>

void swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  swap(&a,&b);
  swap(&a,&c);
  std::cout<<a<<" "<<b<<" "<<c<<std::endl;
}
