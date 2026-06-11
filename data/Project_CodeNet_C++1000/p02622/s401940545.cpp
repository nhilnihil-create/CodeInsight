#include <iostream>

using namespace std;

int main()
{
    string x,y;
    cin>>x>>y;
    int z=y.length();
    int cnt=0;

    for(int i=0;i<z;i++)
    {
        if(x[i]!=y[i])
        {
            cnt++;
        }
    }

    cout<<cnt;
}
