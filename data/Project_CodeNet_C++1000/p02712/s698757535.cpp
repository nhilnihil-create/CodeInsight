 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
  ll n;
  cin>>n;
  ll count = 0;
  for(ll i=1;i<=n;i++){
    if(i%3==0||i%5==0){
      
    }else{
      count = count + i;
    }
  }
  cout<<count<<endl;
}