#include<iostream>
using namespace std;
int main()
{
    int x,i,j,m;
    cin>>x;
    for(i=x;;i++)
    {
        int prime=1;
        for(j=2;j<=i/2;j++)
        {
            if(i%j==0)
            {
                prime=0;
                break;
            }
        }
        if(prime==1)
        {
          m=i;
          break;
        }
    }
    cout<<m<<endl;
    return 0;
}