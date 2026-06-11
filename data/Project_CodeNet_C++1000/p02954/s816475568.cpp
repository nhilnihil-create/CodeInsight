#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  string s;
  cin>>s;
  ll n = s.size();
  vector<ll> ans(n);
  for(ll i=0;i<s.size()-1;i++){
  	if(s[i] == 'R' && s[i+1] =='L'){
    	for(ll j=i;j>=0 && s[j]=='R';j--){
        	if((i-j)%2==0)
              ans[i]++;
          	else ans[i+1]++;
        }
      	for(ll j=i+1;j<n && s[j]=='L';j++){
        	if((j-i)%2==0)
              ans[i]++;
          	else ans[i+1]++;
        }
    }
  }
  for(auto i:ans)
    cout<<i<<" ";
}
  