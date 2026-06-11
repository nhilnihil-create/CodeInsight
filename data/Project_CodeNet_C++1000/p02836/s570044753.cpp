 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
  string s;
  cin>>s;
  ll len = s.length();
  ll count = 0;
  for(ll i=0;i<len/2;i++){
    if(s[i]!=s[len-i-1]) count++;
  }
  cout<<count<<endl;
}