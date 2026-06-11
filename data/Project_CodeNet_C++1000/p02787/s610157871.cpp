#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pnn=pair<int ,int>;

#define ft first
#define sd second
#define fn front
#define pb push_back
#define it insert
#define si(v) int((v).size())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sot(x) sort(x.begin(), x.end())
#define rese(x) reverse(x.begin(), x.end())
#define vnn(x,y,s,name) vector<vector<int>> name(x, vector<int>(y,s))
#define mse(x) memset(x, 0, sizeof(x))
#define mii(x,y,z) min(x,min(y,z))
#define maa(x,y,z) max(x,max(y,z))

string yes="Yes",no="No";

int main() {
  ll h,n;
  cin>>h>>n;
  vll a(n),b(n);
  rep(i,n) cin>>a[i]>>b[i];
  vll mima(h+1,100100100);
  mima[0]=0;
  rep(i,n){
      rep(j,h){
          mima[min(h,j+a[i])]=min(mima[min(h,j+a[i])],mima[j]+b[i]);
      }
      
      rep(j,h) mima[h-j-1]=min(mima[h-j],mima[h-1-j]);
  }

  cout<<mima[h]<<endl;
}
