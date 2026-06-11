#include <iostream>

using namespace std;
#define RAJVI ios_base::sync_with_stdio(false);
#define DAIICT cin.tie(NULL);cout.tie(NULL);

int main()
{
    RAJVI
    DAIICT;
    
    int a=0,b=0,k=-1;
    cin>>a>>b;
    if((a+b)%2==0)
    {
     k=(a+b)/2;
     cout<<k;
        
    }
    else 
    {
        cout<<"IMPOSSIBLE";
        
    }
    
}
