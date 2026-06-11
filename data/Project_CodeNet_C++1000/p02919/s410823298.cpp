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
  int n;
  cin>>n;
  vector<int> p(n);
  rep(i,n)cin>>p[i];
  rep(i,n)p[i]--;
  vector<int>idx(n);
  rep(i,n)idx[p[i]]=i;
  set <int>s;
  ll ans=0;
  int l1,l2,r1,r2;
  for (int i=n-1;i>=0;i--){
    int x=idx[i];
    {
    s.insert(x);
  

    l1=-1;l2=-1;r1=n;r2=n;
    {
    auto it=s.find(x);
    if (it!=s.begin()){it--;l1=*it;}
    if (it!=s.begin()){it--;l2=*it;}
  }{
    auto it=s.find(x);
    it++;
    if (it!=s.end()){r1=*it;it++;}
    if (it!=s.end()){r2=*it;}
  }
}


    ll c=0;
    int ls1,ls2,rs1,rs2;
    ls1=x-l1;ls2=l1-l2;rs1=r1-x;rs2=r2-r1;

    c=(ll)ls1*rs2+(ll)ls2*rs1;

    ans+=c*(i+1);
  }
  cout<<ans;
}
