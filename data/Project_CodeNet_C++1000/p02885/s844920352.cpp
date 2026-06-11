#include <iostream>

using namespace std;

int main()
{
    int A,B,r;

    cin>>A>>B;

    r=A-(B+B);

    if(r>0){
        cout<<r;
    }
    else
        cout<<0;

}