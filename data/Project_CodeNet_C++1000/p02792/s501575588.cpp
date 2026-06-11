#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll n,i,ans,l,k,j;
    string s;
    cin>>n;
    if(n<10){
        cout<<n<<endl;
        return 0;
    }
    vector<vector<ll>>a(11,vector<ll>(11));
    for(i=1;i<=n;i++){
      s=to_string(i);
      l=s.size();
      if(s[l-1]!='0'){
        j=s[0]-48;
        k=s[l-1]-48;
        a[j][k]++;
      }
    }
    ans=0;

    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++)
         ans+=a[i][j]*a[j][i];
    }
    cout<<ans<<endl;
}
