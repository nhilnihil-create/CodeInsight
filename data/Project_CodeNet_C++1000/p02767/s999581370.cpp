#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int a,ans=1000000000;
    cin>>a;
    vector<int> data(a);
    for(int i=0;i<a;i++) cin>>data[i];
    sort(data.begin(),data.end());
    for(int i=data[0];i<=data[a-1];i++)
    {
        int sum=0;
        for(int k=0;k<a;k++)
        {
            sum+=(data[k]-i)*(data[k]-i);
        }
        ans=min(ans,sum);
    }
    cout<<ans;
}