#include <bits/stdc++.h>
using namespace std;
#define INF 1e18
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int a,v,b,w,t;
  cin>>a>>v>>b>>w>>t;
  int d=abs(a-b);
  if(v<=w){
    cout<<"NO"<<endl;
    return 0;
  }
  int s=v-w;
  if(d<=(ll)s*t){
    cout<<"YES"<<endl;
  }
  else {
    cout<<"NO"<<endl;
  }
  return 0;
}
  