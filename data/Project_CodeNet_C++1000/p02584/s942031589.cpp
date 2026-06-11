 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  fi0 for(ll i=0;i<n;i++)
string s;
string strd(int n){
    string x;
    while(n){
        int d=n%10;
        x+=(d+'0');
        n/=10;
    }
    reverse(x.begin(),x.end());
    return x;
}
void digit()
{
    cin>>s;
    ll sum=0;
    for(int i=0;i<s.size();i++){
        char a=(char)s[i];
        int d=(int) a-'0';
        sum+=d;
    }
    if(sum%9==0)cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
   ll n,m,k;
   cin>>n>>m>>k;
   n=abs(n);
        ll dd=min(n/k,m);
        m-=dd;
        n-=(dd*k);
      /// cout<<dd<<' '<<m<<' '<<endl<<n<<endl;
        if(m%2==0)cout<<n<<endl;
        else cout<<abs(k-n)<<endl;

 ///  cout<<m<<endl<<k
}
