#include <bits/stdc++.h>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define e_b emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

//rang add, get point
struct SegmentTree{
private:
  int N;
  vector<long long> node;
  long long identity=0;
public:
  SegmentTree(vector<long long> v){
    int SZ=(int)v.size();
    N=1;
    while(N<SZ) N*=2;
    node.resize(2*N-1,identity);

    for(int i=0;i<SZ;i++) node.at(i+N-1)=v.at(i);
    for(int i=N-2;i>=0;i--) node.at(i)=0;
  }

  long long getpoint(int i){
    i+=N-1;
    long long ans=node.at(i);
    while(i>0){
      i=(i-1)/2;
      ans+=node.at(i);
    }
    return ans;
  }

  void add(int a,int b,long long x,int k=0,int l=0,int r=-1){
    if(r==-1) r=N;
    if(r<=a || b<=l)  return;
    if(a<=l && r<=b){
      node.at(k)+=x;
      return;
    }
    add(a,b,x,2*k+1,l,(l+r)/2);
    add(a,b,x,2*k+2,(l+r)/2,r);
    return;
  }
};

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  ll D,A;
  cin >> N >> D >> A;
  vector<pair<ll,ll>> XH(N);
  for(int i=0;i<N;i++)  cin >> XH.at(i).fi >> XH.at(i).se;

  sort(all(XH));
  vector<ll> X(N),H(N);
  for(int i=0;i<N;i++){
    X.at(i)=XH.at(i).fi;
    H.at(i)=XH.at(i).se;
  }

  ll ans=0;
  SegmentTree seg(H);
  for(int i=0;i<N;i++){
    ll tmp=seg.getpoint(i);
    if(tmp<=0)  continue;
    ll cnt=(tmp+A-1)/A;
    int l=i;
    int r=upper_bound(X.begin(),X.end(),X.at(i)+2*D)-X.begin();
    ans+=cnt;
    seg.add(l,r,-cnt*A);
  }
  cout << ans << endl;

  return 0;
}