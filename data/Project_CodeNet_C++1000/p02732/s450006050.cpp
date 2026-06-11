#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N;
  cin >>N;
  vector<ll> vec(N);
  vector<ll> vec1(N);
  for(int i=0;i<N;i++){
    cin >> vec[i];
    vec1[i]=vec[i];
  }
  sort(vec1.begin(),vec1.end());
  ll a=vec1[0];
  ll ans=0;
  map<ll,ll> m;
  for(ll i=0;i<N;i++){
    if(a==vec1[i]){
      m[vec1[i]]++;
      if(i==N-1){
        ans+=m[vec1[i]]*(m[vec1[i]]-1)/2;
      }
    }
    else{
      ans+=m[a]*(m[a]-1)/2;
      a=vec1[i];
      m[vec1[i]]++;
    }
  }
  ll d=ans;
  for(ll i=0;i<N;i++){
    ans+=(m[vec[i]]-1)*(m[vec[i]]-2)/2-m[vec[i]]*(m[vec[i]]-1)/2;
    cout << ans <<endl;
    ans=d;
  }
}
    