#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  vector<string> s(n);
  for(int i=0;i<n;i++)cin >> s[i];

  for(int i=0;i<n;i++){
    sort(s[i].begin(),s[i].end());
  }
  sort(s.begin(),s.end());

  ll c=0;
  string a=s[0];
  ll b=upper_bound(s.begin(),s.end(),a)-lower_bound(s.begin(),s.end(),a);
  c+=b*(b-1)/2;
  for(int i=0;i<n;i++){
    if(a==s[i])continue;
    else{
      a=s[i];
      b=upper_bound(s.begin(),s.end(),a)-lower_bound(s.begin(),s.end(),a);
      c+=b*(b-1)/2;
    }
  }

  cout << c << endl;



}