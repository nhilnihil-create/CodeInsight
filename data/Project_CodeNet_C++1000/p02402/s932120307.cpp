#include <iostream>
using namespace std;
int main(){
    int a=0,n=0,c=1000000,b=-1000000;
    long long d=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(a<c)
        {
            c=a;
        }
        if(b<a){
            b=a;
        }
        
        d=d+a;
        
    }
    cout<<c<<" "<<b<<" "<<d<<endl;
    return 0;
}

