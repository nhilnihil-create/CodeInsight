#include <iostream>

using namespace std;

int main()
{
    int x, p1,p2 ;
    cin>>x;
    int Arr[x];
    for(int i=0; i<x; i++)
    {
        cin>>Arr[i];
    }
    bool f=false;
    int count =0;
    for(int i=0; i<(x-1); i++)
    {
        if(Arr[i]<Arr[i+1])
            continue;
        else if(Arr[i]>Arr[i+1])
        {
            if(count==0)
                p1=i;
            else
                p2=i+1;
            f=true;
            count++;
        }
    }



    if(!f)
        cout<<"YES";

    else
    {
        if(count<=2)
        {
            if(count==1)
                p2=x-1;
            swap(Arr[p1],Arr[p2]);

              if(Arr[p1]<Arr[p1+1] &&  Arr[p2]>Arr[p2-1])
                cout<<"YES";
              else
                cout<<"NO";

         }

        else
            cout<<"NO"<<endl;

    }

    return 0;
}
