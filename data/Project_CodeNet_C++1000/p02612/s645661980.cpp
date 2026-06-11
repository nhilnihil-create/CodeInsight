#include<iostream>
using namespace std;
int main()
{
    int N,i,j;
    cin>>N;
        for(i=10000; i>=0; i-=1000)
        {if(N%1000==0)
            j=0;
 else if(N%1000!=0)
            if(N<i)
                j=i-N;
        }
        cout<<j<<endl;

    return 0;
}
