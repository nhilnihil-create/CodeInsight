#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> data(n);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        if((a==1&&b==0)&&n!=1)
        {
            cout<<"-1";
            return 0;
        }
        if(data[a-1]==0||data[a-1]==b) data[a-1]=b;
        else
        {
            cout<<"-1";
            return 0;
        }
    }
    if(data[0]==0&&n!=1) data[0]=1;
    for(int i=0;i<n;i++)
        cout<<data[i];
}