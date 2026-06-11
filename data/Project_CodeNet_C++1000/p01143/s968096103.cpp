#include <iostream>
using namespace std;

int main()
{
    int N,M,P,i,j,k,sum=0,gold=0,h,w,get;
    int x[100];

    for (i=0; ; i++)
    {
        cin>>N>>M>>P;
        if (N==0&&M==0&&P==0)
        {
            break;
        }
        for (j=1; j<N+1; j++)
        {
            cin>>x[j];
            sum=sum+x[j];
        }
        gold=sum*100;
        w=100-P;
        h=gold*w/100;
        
        for (k=1; ; k++)
        {
            if (k==M)
            {
                if(x[k]==0)
                {
                    cout<<0<<endl;
                    break;
                }
                    
                get=h/x[k];
                cout<<get<<endl;
                break;
            }
        }
        sum=0;
        h=0;
    }

    return 0;
}