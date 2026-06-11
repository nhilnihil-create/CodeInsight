#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int main()
{
    int N,x,count=0;
    cin>>N;  
    for ( int i = 1; i <= N; i++)
    {
        x=log10(i);
        
        if ((x%2)==0){
            count++;
        }

    }
    
    cout<<count;
    return 0;
}

