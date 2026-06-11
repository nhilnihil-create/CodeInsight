#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    ios;
    int n,d;
    cin>>n>>d;
    vector<vector<int> > x(n, vector<int>(d));

    for(int i=0;i<n;i++)
        for(int j=0;j<d;j++)
        cin>>x[i][j];

        int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=0;
            for(int k=0;k<d;k++)
            {
                int s=abs(x[i][k]-x[j][k]);
                sum+=s*s;
            }
            int k=sqrt(sum);
            if(k*k==sum)
                ans++;
        }
    }
    cout<<ans<<endl;


}









































