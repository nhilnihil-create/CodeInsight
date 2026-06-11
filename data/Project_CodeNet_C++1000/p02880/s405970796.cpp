#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=9;i++)
    {
        if(n%i==0){
        int x=n/i;
        if(x<=9)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
        }
    }
    cout<<"No"<<endl;
}
