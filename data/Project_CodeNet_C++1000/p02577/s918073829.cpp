#include<bits/stdc++.h>
#define ll long long
#define t ll t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(void){
  fast;
  // Code from here....
  string str;
  cin>>str;
  ll sum = 0;
  for(int i=0; i<str.length(); i++){
    sum += (int)str[i] -48;
  }
  (sum%9 == 0) ? cout<<"Yes" : cout<<"No";
}