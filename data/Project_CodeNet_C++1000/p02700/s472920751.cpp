#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int a,b,c,d,sign=1;
    cin>>a>>b>>c>>d;
    while(1){
        if(sign==1){
            sign=0;
            c-=b;
        }
        else{
            sign=1;
            a-=d;
        }
        if(a<=0 || c<=0) break;
    }
    if(sign==1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
