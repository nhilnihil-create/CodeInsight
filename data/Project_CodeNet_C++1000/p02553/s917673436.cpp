#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef vector<int> vec;
int main(){
  long a,b,c,d; cin>>a>>b>>c>>d;
  if(b>0&&d>0)cout<<max(a*c,b*d);
  else if(a<0&&c<0)cout<<a*c;
  else cout<<max(a*d,b*c);

}