#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define eps 1e-9

using namespace std;
int arr[1000001];
int main()
{

    ll t,n,m,f,a,b,c,l,r,q,k,x,y,z,ans,mn,mx,sum=0;
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);


    cin>>n;
    vector< ll > in;

    mx = -1;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        mx = max(mx,x);

        if(arr[x]==1)
        {
            arr[x]=-1;
        }
        else if(arr[x]==0)
        {
            arr[x]=1;
            in.push_back(x);
        }
    }

    //cout<<"HERE"<<endl;


    for(int i=0;i<in.size();i++)
    {
        x = c = in[i];

        while(1)
        {
            x+=c;
            if(x<=mx)
            arr[x]=0;
            else
                break;
        }
    }

    c=0;
    for(int i=0;i<1000001;i++)
    {
        if(arr[i]==1)
        {
            c++;
        }
    }

    cout<<c<<endl;


}
