#include <bits/stdc++.h>
using namespace std;
#define ll long long
using  P=pair<ll,ll>;
int main(){
  ll N;
  cin>>N;
  vector<P> vec;
  for(ll i=0;i<N;i++){
    ll a,b;
    cin>>a>>b;
    vec.push_back(make_pair(b,a));
  }
  sort(vec.begin(),vec.end());
  ll sumtime=0;
  for(ll i=0;i<N;i++){
    //cout<<vec.at(i).first<<" "<<vec.at(i).second<<endl;
    sumtime+=vec.at(i).second;
    if(sumtime>vec.at(i).first){cout<<"No"<<endl;return 0;}
  }
  cout<<"Yes"<<endl;
}