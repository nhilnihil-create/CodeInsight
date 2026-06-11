#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    bool t=false;
    int count=0;
    for(int i=0;i<n;i++)
    {
        int d1,d2;
        cin>>d1>>d2;
        if(d1==d2)
        count++;
        else
        count=0;

        if(count>=3)
        {
        t=true;
        break;
        }
    }
    if(t==true)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}
