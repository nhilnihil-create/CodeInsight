#include<bits/stdc++.h>
using namespace std;
int main()
{
    int r,c;
    while(1)
    {
        cin>>r>>c;
        if(r==0 && c==0)
            break;
        else
        {
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if(j%2==0 && i%2==0)
                        cout<<"#";
                    else if(j%2==1 && i%2==1)
                        cout<<"#";

                    else
                        cout<<".";
                }
                cout<<endl;
            }
        }

        cout<<endl;
    }

    return 0;
}

