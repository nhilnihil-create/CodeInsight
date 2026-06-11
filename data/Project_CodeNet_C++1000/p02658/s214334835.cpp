#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define pb push_back
#define si second
#define int long long
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define double long double
#define all(o) o.begin(),o.end()
using namespace std;
int n,ele,cur=1;

int32_t main(){
 //   fast

    cin>>n;
    int i;
    vector<int> v(n);
    int z=0;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]==0)
            z=1;
    }
    if(z==1)
        cout<<"0\n";
    else{
        for(i=0;i<n;i++)
        {
            if(cur>(1e18)/v[i])
            {
                cur=-1;
                break;
            }
            else cur*=v[i];
        }


        if(cur>((int)1e18) || cur==-1)
            cur=-1;
        cout<<cur<<"\n";
    }









    
}


