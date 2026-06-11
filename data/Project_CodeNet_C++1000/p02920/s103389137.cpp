#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct segtree{
private:
  ll siz;
  vector<ll> node;
  priority_queue<P> pque;
  queue<P> que;
public:
  segtree(ll k){
    siz=1<<k;
    node.resize(siz*2+5,0);
    pque.push(P(siz,0));
  }
  bool upd(ll pos,ll x){
    pos+=siz-1;
    node[pos]=x;
    bool ret=true;
    while(pos>0){
      pos=(pos-1)/2;
      node[pos]=max(node[2*pos+1],node[2*pos+2]);
      if(node[2*pos+1]==node[2*pos+2]) ret=false;
    }
    return ret;
  }
  bool seg_set(ll x,bool last){
    if(pque.empty()) return false;
    P p=pque.top();
    pque.pop();
    bool ret=upd(p.second,x);
    ll two=1,pos=p.second+1;
    while(two<p.first){
      que.push(P(two,pos));
      pos+=two;
      two*=2;
    }
    if(last){
      while(!que.empty()){
        pque.push(que.front());
        que.pop();
      }
    }
    return ret;
  }
};
int main(){
  ll k;
  cin>>k;
  ll n=1<<k;
  vector<ll> vec;
  vec.push_back(0);
  for(ll i=0;i<n;i++){
    ll a;
    cin>>a;
    vec.push_back(a);
  }
  sort(vec.begin(),vec.end(),greater<ll>());
  segtree seg=segtree(k);
  bool ret=true;
  for(int i=0;i<n;i++){
    bool f=vec[i]!=vec[i+1];
    if(!seg.seg_set(vec[i],f)){
      ret=false;
      break;
    }
  }
  cout<<(ret?"Yes":"No")<<endl;
}
