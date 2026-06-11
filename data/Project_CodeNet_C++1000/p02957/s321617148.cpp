#include <iostream>
using namespace std;
int main()
{
    long long int i,a,b,c,d,k=-1;
    
    cin>>a>>b;
    
    for( i=0;i<=1000000000;i++){
         
        if( abs(a-i) == abs(b-i) ){
            k = i ;
            break;
        }
    }


    if( k>-1 ) {
        cout<<k;
    }
    else if( k==-1 ){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}
