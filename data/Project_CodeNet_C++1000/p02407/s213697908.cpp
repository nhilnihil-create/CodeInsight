#include<iostream>
using namespace std;
int kazu[100],n;
int com(){
cin>>n;
for(int a=0;a<n;a++)
cin>>kazu[a];
for(int b=n-1;b>=0;b--){
cout<<kazu[b];
if(b!=0)
cout<<" ";
else
cout<<endl;
}
}
int main(){
com();
return 0;
}