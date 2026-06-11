#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    cin>>n>>m;
    int t;
    string s;
    int a[100001]={0};
    int countw=0,countr=0;
    while(m--)
    {
        cin>>t;
        cin>>s;
        if(s=="WA")
        {
            if(a[t]!=-1)
            a[t]++;
        }
        else
        {
            if(a[t]>=0)
            {
                countw+=a[t];
                countr++;
                a[t]=-1;

            }


        }

    }
    cout<<countr<<" "<<countw<<endl;
}
