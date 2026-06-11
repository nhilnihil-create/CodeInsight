# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int main(){
  int a,b;cin>>a>>b;
  if((a+b)%2==0)
    cout<<(a+b)/2;
  else
    cout<<"IMPOSSIBLE";
  return 0;
}
