//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define For_Arr     for(i=0;i<n;i++)
using namespace std;
int main()
{
    ll n,i,x,prev=0;
    cin>>n;
    ll maxi=-1,cnt=0;
    for(i=0;i<n;i++)
    {
        cin>>x;
        if(prev>=x){
            cnt++;
        }
        else{
        maxi=max(maxi,cnt);
        cnt=0;
        }
        prev=x;
    }
    cout<<max(maxi,cnt)<<endl;


    return 0;
}



