#include<bits/stdc++.h>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

ll ar[200005];

int main()
{
    ll n,a[101],b[101],i,cnt=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    for(i=0;i<n;i++)
    {
        while(a[i]==b[i] && i<n)
        {
            cnt++;
            i++;
        }
        if(cnt<3) cnt=0;
    }
    if(cnt>=3)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
