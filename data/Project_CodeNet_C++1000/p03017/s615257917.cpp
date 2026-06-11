#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define per(i,s,n) for(int i=n-1;i>=s;i--)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  ll n,a,b,c,d;
  cin>>n>>a>>b>>c>>d;
  a--;
  b--;
  c--;
  d--;
  string s;
  cin>>s;
  
  int e=0;
  int ch=0;
  
  if(c<d){
    Rep(i,a,d){
      if(s[i]=='.'){
        e=0;
      }
      else{
        e++;
        ch=max(e,ch);
      }
    }
    Ans(ch<=1);
  }
  
  else{
    Rep(i,a,d){
      if(s[i]=='.'){
        e=0;
      }
      else{
        e++;
        ch=max(e,ch);
      }
    }
    int z=0;
    int x=0;
    Rep(i,b-1,d+2){
      if(s[i]=='.'){
        z++;
        x=max(x,z);
      }
      else{
        z=0;
      }
    }
    
    Ans(ch<=1 && x>=3);
  }
}
