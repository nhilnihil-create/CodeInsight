# include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;

int main(){
ll n,d;cin>>n>>d;
ll x,y,count=0;
while(n--){
  cin>>x>>y;
  x=pow(x,2);y=pow(y,2);
  if(sqrt(x+y)<=d){
    count++;
  }
}
cout<<count;
return 0;

  
}
