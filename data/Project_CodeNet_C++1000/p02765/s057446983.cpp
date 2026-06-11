#include<iostream>
using namespace std;
int main ()
{
    int N,R,S,A;
    cin>>N>>R;
    if(N<10)
    {
    S=100*(10-N);
    A=R+S;
    cout<<A<<endl;
    }
    else
        cout<<R<<endl;
    return 0;

}