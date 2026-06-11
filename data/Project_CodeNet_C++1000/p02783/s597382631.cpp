#include<bits/stdc++.h>
using namespace std;
int main(){
int h,a;
cin>>h>>a;
if(a>=1&&a<=pow(10,4)&&h>=1&&h<=pow(10,4))
{
int n=0;
while(h>0){
    h -= a;
    n++;
}
cout<<n<<endl;}



return 0;}
