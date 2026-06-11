#include<iostream>
using namespace std;
int main(){
int a[4],b[4],sum_a,sum_b;

cin>>a[0]>>a[1]>>a[2]>>a[3];
cin>>b[0]>>b[1]>>b[2]>>b[3];
sum_a=a[0]+a[1]+a[2]+a[3];
sum_b=b[0]+b[1]+b[2]+b[3];

if(sum_a>=sum_b){
cout<<sum_a<<endl;
}else{
cout<<sum_b<<endl;
}

return 0;
}