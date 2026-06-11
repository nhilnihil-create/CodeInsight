#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j,k;
    cin>>n;
    for(i=1;i<=9;i++)
    {
        if(n%i==0 && n/i<=9)
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;

}
