
#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,i,ans,j=0;
    cin>>n;
    int d[n],s[n],ms[n-1];
    for(i=0;i<n;i++){
        cin>>d[i];
    }
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    for(i=0;i<n-1;i++){
        cin>>ms[i];
    }
    ans=s[d[0]-1];
    //cout<<ans<<endl;

    for(i=1;i<n;i++){
        ans+=s[d[i]-1];
      //  cout<<ans<<endl;
        if(d[i]-d[i-1]==1){
            ans+=ms[d[i-1]-1];

        }
    }
    cout<<ans;
}
