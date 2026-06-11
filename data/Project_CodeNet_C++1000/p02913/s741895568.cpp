#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  string s;
  cin >> s;

  ll m=0;

  for(int l=0;l<n;l++){
    string t=s.substr(l);
    vector<ll> Z(t.size());
    Z[0] = t.size();
    int i = 1, j = 0;
    while(i < t.size()){
      while(i + j < t.size() && t[j] == t[i + j]) j++;
      Z[i] = j;

      if(j == 0){
          i++;
          continue;
      }
      int k = 1;
      while(k < j && k + Z[k] < j){
          Z[i + k] = Z[k];
          k++;
      }
      i += k;
      j -= k;
    }

    for(ll p=1;p<Z.size();p++){
      ll q=min(Z[p],p);
      m=max(m,q);
    }

  }

  cout << m << endl;
  

  // ll l=0;
  // ll r=n;
  // ll h;
  // bool kanou=false;
  // vector<vector<ll>> v;
  // while(abs(r-l)>1){
  //   h=(r+l)/2;

  //   kanou=false;


  //   for(ll i=0;i<n-2*h+1;i++){
  //     for(ll j=i+h;j<n-h+1;j++){
  //       //1つ目の方法(失敗)
  //       // if(s[i]==s[j]){
  //       //   string u,v;
  //       //   u=s.substr(i,h);
  //       //   v=s.substr(j,h);
  //       //   if(u==v){
  //       //     kanou=true;
  //       //     break;
  //       //   }
  //       // }
  //       //2つ目の方法(失敗)
  //       ll m=0;
  //       for(ll k=0;k<h;k++){
  //         if(s[i+k]==s[j+k])m++;
  //         else break;
  //       }
  //       if(m==h){
  //         kanou=true;
  //         v.push_back({i,j});
  //       }
  //     }
  //     //if(kanou)break;
  //   }

  //   if(kanou)break;
  //   else r=h;
  // }

  // //cout << v[0][0] <<v[0][1]<< endl;

  // if(!kanou)h=0;

  // h++;

  // //cout << h << endl;

  // while(!v.empty()){
  //   vector<vector<ll>> u;
  //   for(ll i=0;i<v.size();i++){
  //     if(v[i][1]-v[i][0]==h-1)continue;
  //     if(v[i][1]+h-1==n)continue;
  //     if(s[v[i][0]+h-1]==s[v[i][1]+h-1])u.push_back({v[i][0],v[i][1]});
  //   }
  //   //if(h==4)cout << u[0][0] << " " << u[0][1] << endl;
  //   v=u;
  //   if(!u.empty())h++;
  // }
  // h--;



  // cout << h << endl;

}