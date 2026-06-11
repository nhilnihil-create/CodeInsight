#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
int32_t main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int R=0,G=0,B=0,sum=0;
    for(int i=0;i<n;i++)if(s[i]=='R')R++;else if(s[i]=='G')G++;else B++;
//    cout<<R<<" "<<G<<' '<<B<<endl;
//    cout<<R*G*B<<endl;
    sum=R*G*B;
//    rep(i,n){
//	    for(int j=1;j<=n;++j){
//		    int ni=i-j,nj=i+j;
//		    if(ni<0 ||nj>=n)break;
//		    if(s[i]!=s[ni]&&s[i]!=s[nj]&&s[ni]!=s[nj]){--sum;}//naritatanaikarahiku
//	    }
//    }
    for(int j=0;j<n;j++)
    {
    for(int i=1;i<=n;i++)
        {
            int a=j-i,b=i+j;
            if(a<0||b>=n)break;
          if(s[j]!=s[a]&&s[j]!=s[b]&&s[a]!=s[b])sum--;
        }
    }
        cout<<sum<<endl;
}
