#include <iostream>

using namespace std;

int main()
{
    int X,A;
    cin>>X>>A;
if(X>=0&&A>=0&&X<=9&&A<=9){
    if(X<A){
        cout<<0;
    }
    else{
        cout<<10;
    }
}
    return 0;
}