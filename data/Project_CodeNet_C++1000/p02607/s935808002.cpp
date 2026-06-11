#include <iostream>

using namespace std;

int main()
{
    int a[100000] ,n ;
    cin>>n;
    int i , c=0;
    for(i=1;i<=n;i++){cin>>a[i];}
    for(i=1;i<=n;i++){
        if(i%2!=0){
            if(a[i]%2!=0){c=c+1;}
        }}
        cout<<c;
    return 0;
}

