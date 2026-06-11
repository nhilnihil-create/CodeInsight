#include<iostream>
using namespace std;
int main(){
int aa,ab,ac,ad,ba,bb,bc,bd,sum_a,sum_b;

cin>>aa>>ab>>ac>>ad;
cin>>ba>>bb>>bc>>bd;
sum_a=aa+ab+ac+ad;
sum_b=ba+bb+bc+bd;

if(sum_a>=sum_b){
cout<<sum_a<<endl;
}else{
cout<<sum_b<<endl;
}

return 0;
}