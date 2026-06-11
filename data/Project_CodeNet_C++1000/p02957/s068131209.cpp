#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n,a,b,c,d,x,y,z,p;
    double k;


    cin>>a>>b;
    if(a!=b)
    {
        k=(a+b)*0.5;
        if(k==(int)k)
        {
            x=abs(a-k);
            y=abs(b-k);
            //cout<<"x: "<<x<<endl;
            //cout<<"y: "<<y<<endl;
            if(x==y)
            {
                cout<<fixed<<setprecision(0)<<k<<endl;
            }
            else {
                cout<<"IMPOSSIBLE"<<endl;
            }

        }
        else{
            cout<<"IMPOSSIBLE"<<endl;}
    }

    return 0;
}

