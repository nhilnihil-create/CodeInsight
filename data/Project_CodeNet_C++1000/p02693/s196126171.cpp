#include<bits/stdc++.h>
using namespace std;
int main()
{
    int div,a,b,count;
    while(cin>>div>>a>>b)
    {
        count=0;
        for(int i=a;i<=b;i++)
        {
            if(i%div==0)
            {
                count++;
                 break;
            }
        }
        if(count!=0)
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<"NG"<<endl;
        }
    }
}
