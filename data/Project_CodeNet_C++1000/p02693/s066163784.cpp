#include <iostream>
#include <string>

using namespace std;

int main()
{
int K;
int A,B;
cin>>K;
cin>>A>>B;

int P=B/K;
int R=P*K;
if(A<=R)
{
    cout<<"OK";
}
else
{
    cout<<"NG";
}
return 0;
}
