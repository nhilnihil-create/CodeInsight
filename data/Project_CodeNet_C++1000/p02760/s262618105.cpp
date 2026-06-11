#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
vector<vector<ll>> A(3,vector<ll>(3));
  for(ll i=0;i<3;i++) {
    for(ll j=0;j<3;j++) {
cin>>A[i][j];
    }
  }
  vector<vector<bool>> bingo(3,vector<bool>(3));
  ll N;
  cin>>N;
  for(ll i=0;i<N;i++) {
ll b;
    cin>>b;
  for(ll i=0;i<3;i++) {
for(ll j=0;j<3;j++) {
  if(A[i][j]==b) {
bingo[i][j]=true;
  }
}
  }
  }
  
  
  bool j=false;
  for(ll i=0;i<3;i++) {
    ll count=0;
for(ll j=0;j<3;j++) {
  if(bingo[i][j]) {
count++;
  }
}
    if(count==3) {
j=true;
    }
  }
  
  
 for(ll i=0;i<3;i++) {
   ll count=0;
for(ll j=0;j<3;j++) {
  if(bingo[j][i]) {
count++;
  }
}
   
   if(count==3) {
j=true;
   }
 }
    
  ll count=0;
  for(ll i=0;i<3;i++) {
    if(bingo[i][i]) {
count++;
    }
  }
    
if(count==3) {
j=true;
}
  ll t=0;
  for(ll i=0;i<3;i++) {
    if(bingo[i][2-i]) {
t++;
    }
  }
    
if(t==3) {
j=true;
}
  
  
 
    if(j) {
cout<<"Yes"<<endl;
  }
else {
cout<<"No"<<endl;
}
}




  
  
  
  
  

  
