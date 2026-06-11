#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  ll n,k,s;
  cin >> n >> k >> s;
  ll i;
  if(s==1000000000){
    for(i=0;i<k;i++){
      cout << s << " ";
    }
    for(i=k;i<n;i++){
      cout << 1 << " ";
    }
  }else{
    for(i=0;i<k;i++){
      cout << s << " ";
    }
    for(i=k;i<n;i++){
      cout << s+1 << " ";
    }
  }
}