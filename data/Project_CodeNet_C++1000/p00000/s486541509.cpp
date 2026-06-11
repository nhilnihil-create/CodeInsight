#include<iostream>
using namespace std;
int main(){
int i;
int x;
int y;
for(i=1;i<=9;i++){
for(x=1;x<=9;x++){
y=i*x;
cout<<i<<"x"<<x<<"="<<y<<endl;
}
}
return 0;
}