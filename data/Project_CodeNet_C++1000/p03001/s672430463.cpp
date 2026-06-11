#include <iostream>
#include<iomanip>
using namespace std;
int main(void){
    // Your code here!
double w,h,x,y;
cin>>w>>h>>x>>y;

cout<<fixed<<setprecision(6)<<(w*h)/2;
if(x==w/2 && y==h/2)
    cout<<" "<<1;
else
cout<<" "<<0;
}
