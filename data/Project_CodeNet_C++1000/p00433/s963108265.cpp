#include <iostream>
using namespace std;
int main(){
 int i,in,s=0,t=0;
 for(i=0;i<4;i++){cin>>in;s+=in;}
 for(i=0;i<4;i++){cin>>in;t+=in;}
 if (t>s)s = t;
 cout<<s<<endl;
}