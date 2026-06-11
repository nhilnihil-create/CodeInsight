#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n;
    cin>>n;
    double cnt=0;
    double x;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        {
            cnt++;
        }

    }
     x=cnt/n;
    cout<<fixed<<setprecision(10)<<double(x)<<endl;

}
