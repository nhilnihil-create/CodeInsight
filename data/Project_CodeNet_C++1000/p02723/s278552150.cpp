#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int main()
{
    char line[7];
    for(int i=0;i<6;i++)
    {
        cin>>line[i];
        if(i==3)
        {
            if(line[i]!=line[i-1])
            {
               cout<<"No";
               return 0;
            }
        }
        else if(i==5)
        {
            if(line[i]!=line[i-1])
            {
               cout<<"No";
               return 0;
            }
        }
    }
    cout<<"Yes";
    return 0;
}

