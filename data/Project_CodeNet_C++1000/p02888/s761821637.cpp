#include <iostream>

using namespace std;
bool judge(int a,int b,int c);
int main()
{
    int n;
    int num=0;
    cin>>n;
    int lenth[n+5];
    for(int i=0;i<n;i++)
        cin>>lenth[i];
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(judge(lenth[i],lenth[j],lenth[k]))
                    num++;
            }
        }
    }
    cout<<num;
    return 0;
}

bool judge(int a,int b,int c)
{
    if(a<b+c)
        if(b<a+c)
            if(c<a+b)
                return 1;
    return 0;
}
