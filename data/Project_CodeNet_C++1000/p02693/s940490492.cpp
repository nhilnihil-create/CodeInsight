#include<iostream>
using namespace std;
int main()
{
    unsigned int k,a,b,sign=0,i;
    cin>>k>>a>>b;
    for(i=a/k;k*i<=b;i++){
        if(k*i>=a && k*i<=b){
            sign=1;
            break;
        }
    }
    if(sign==1) cout<<"OK"<<endl;
    else cout<<"NG"<<endl;
    return 0;
}
