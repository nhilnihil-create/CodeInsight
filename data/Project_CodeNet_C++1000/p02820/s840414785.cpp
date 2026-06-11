#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll a,b,c;

char katsute(char d){
  if(d=='r')return 'p';
  else if(d=='s')return 'r';
  else return 's';
}

ll tokuten(char d){
  if(d=='r')return c;
  else if(d=='s')return a;
  else return b;
}

int main(){

  ll n,k;
  string t;
  cin >> n >> k >> a >> b >>c >> t;

  string u=t;
  for(ll i=0;i<n;i++){
    u[i]='.';
  }

  ll s=0;

  for(ll i=0;i<k;i++){
    u[i]=katsute(t[i]);
    s+=tokuten(t[i]);
  }

  //cout << u[0] << " " << u[1] << endl;


  for(ll i=k;i<n;i++){
    if(t[i]==t[i-k]){
      if(u[i-k]=='a'){
        u[i]=katsute(t[i]);
        s+=tokuten(t[i]);
      }
      else{
        u[i]='a';
      }
    }
    else{
      u[i]=katsute(t[i]);
      s+=tokuten(t[i]);
    }
  }

  //for(ll i=0;i<n;i++)cout << u[i];

  cout << s << endl;

}