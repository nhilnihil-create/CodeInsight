#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,c=0,n,p=0,g,j,r;
    int a[1000]= {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

    cin>>n;
    /* for(i=1; i<g; i++)
                 for(j=0; j<g-i; j++)
                     if(a[j]>a[j+1])
                     {
                         r=a[j];
                         a[j] = a[j+1];
                         a[j+1]=r;

                     }









    cout<<a<<endl;*/




    for(i=0;; i++)
    {



        c++;
        if(c==n)
        {

            cout<<a[i]<<endl;
            break;
        }


    }







    return 0;
}
