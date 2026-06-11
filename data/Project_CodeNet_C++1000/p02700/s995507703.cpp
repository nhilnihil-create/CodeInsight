#include <iostream>
using namespace std;
int main(void){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int e;
    e=(a-1)/d;
    if(c<=b*(e+1)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
