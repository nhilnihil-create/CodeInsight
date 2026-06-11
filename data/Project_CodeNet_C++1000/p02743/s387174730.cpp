#include <iostream>
using namespace std;

int main(void){
    long long a,b,c;
    cin>>a>>b>>c;
    if(c>a+b && (c-a-b)*(c-a-b)>4*a*b) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}