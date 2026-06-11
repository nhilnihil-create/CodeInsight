#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
   for(int i = 0; i < n; i++) cin>>arr[i];
   for(int i = 0; i < n; i++) arr[i]--;
   vector<ll> s(n+1);
   for(int i = 0; i < n;  i++) s[i+1] = (s[i]+arr[i])%k;
   map<ll,ll> mp;
   ll ans = 0;
   queue<ll> q;
   for(int i = 0; i <= n; i++){
       ans+=mp[s[i]];
       mp[s[i]]++;
       q.push(s[i]);
       if(q.size() == k){
           mp[q.front()]--;
           q.pop();
       }
   }
  cout<<ans;
}
