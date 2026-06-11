#include <iostream>
using namespace std;
int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    int a1=a+b;
    int a2=b+c;
    int a3=c+a;
    int ans=min(min(a1,a2), a3);
    cout<<ans<<endl;
}
