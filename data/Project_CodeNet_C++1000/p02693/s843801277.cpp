#include<iostream>
using namespace std;
int main()
{
    int k,a,b;
    while(cin>>k)
    {
        cin>>a>>b;
        int cnt=0;
        for(int i=a;i<=b;i++)
        {
            if(i%k==0)
            {
                cnt=1;
                break;
            }
        }
        if(cnt==1)
        {
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<"NG"<<endl;
        }
    }
}
