#include <iostream>
 
using namespace std;
 
int main()
{
    int k,a,b;
    cin>>k>>a>>b;
    int c=(b/k)*k;
    if(c>=a)cout<<"OK"<<endl;
    else cout<<"NG"<<endl;
 
    return 0;
}