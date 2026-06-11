#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, i, j, k=0, m, p=0, f=0, a[3], x, y, z;
    cin>>n;
    unordered_map<ll, ll>mp;
    a[0]=0, a[1]=0, a[2]=0;
    for(i=0; i<n; i++){
        cin>>j;
        if(j!=0)p=j;
        if(mp[j]==0){
            k++;
            if(k>=4){
                f=1;
            }
            else{
                a[k-1]=j;
            }
        }
        mp[j]++;
    }
    if(f==1){
        cout<<"No"<<endl;
    }
    else{
        x=mp[a[0]];
        y=mp[a[1]];
        z=mp[a[2]];
        if(mp.size()==1){
            if(a[0]==0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else if(mp.size()==2){
            if(mp[0]==0)cout<<"No"<<endl;
            else{
                if(mp[p]==2*mp[0])cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
        }
        else if(mp.size()==3){
            if((a[0]^a[1]^a[2])==0){
                if(x==y && x==z)cout<<"Yes"<<endl;
                else cout<<"No"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
         else cout<<"No"<<endl;
    }
    return 0;
}
