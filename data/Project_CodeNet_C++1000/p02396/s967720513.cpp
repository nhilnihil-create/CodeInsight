
#include <iostream>
using namespace std;
int main(){

int a ;
int i ;

for(i=1;i<=10000;i++)
    {
    cin >> a ;
    if(a!=0)
    cout<<"Case "<< i <<": "<< a <<endl;
    else
    break;
    }

return 0;
}
