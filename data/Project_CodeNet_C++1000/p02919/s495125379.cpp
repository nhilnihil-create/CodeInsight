





#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i,n) for(int i=0;i<n;++i)


//vector<vector<int>> z(n,vector<int>(2));
//n番目から数えてm個の文字列をXに置換したい場合はreplace(n,m,X) teWttest
//s1.substr(3,3);
//n番目以降の文字列をm個取り出す、上だとtte

int main(){
  ll n;
  cin>>n;
  vector<ll> p(n);
  rep(i,n)cin>>p[i];
  rep(i,n)p[i]--;
  vector<ll> idx(n);
  rep(i,n) idx[p[i]]=i;
  ll ans=0;
  set<int>s;
  for(int i=n-1;i>=0;i--){
    s.insert(idx[i]);
    auto it=s.find(idx[i]);
    vector<int> l(2,-1);
    vector<int>r(2,n);
    vector<int> l1(2),r1(2);
    rep(j,2){
      if (it==s.begin())break;
      it--;
      l[j]=*it;
  //    cout<<l[j]<<'l'<<i<<endl;
    }
    it=s.find(idx[i]);
    rep(j,2){
      it++;
      if (it==s.end())break;
      r[j]=*it;
  //      cout<<r[j]<<'r'<<i<<endl;
    }
    l1[0]=idx[i]-l[0];
    l1[1]=l[0]-l[1];
    r1[0]=r[0]-idx[i];
    r1[1]=r[1]-r[0];
    ans+=ll(l1[0]*r1[1]+l1[1]*r1[0])*ll(i+1);
  //  cout<<(l1[0]*r1[1]+l1[1]*r1[0])<<endl;
  }
  cout<<ans;




  }
