#include <iostream>
using namespace std;

int main() {
int N,L,i,x=0;
cin>>N;
for(i=1;i<=N;i++)
{
    cin>>L;
    if(i%2!=0)
    {
        if(L%2!=0)
        x++;
    }
}
cout<<x<<endl;
    return 0;
}