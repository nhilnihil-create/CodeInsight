#pragma GCC optimize ("O3")
#include<map>
#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
#include<queue>
#include<math.h>
#include<bitset>
#include<random>
#include<set>
using namespace std;
using ll = __int64_t;
using lll = __int128_t;
typedef pair<ll,ll> P;
#define REP(i,b,e) for(ll i=(ll)b;i<(ll)e;i++)
#define rep0(i,n) REP(i,0ll,n)
#define rep1(i,n) REP(i,1ll,n+1)
const ll longinf=1ll<<60;
const int inf=(1<<30)-1;
const ll mod=1e9+7;


int main(){
      int n;
      cin>>n;
      int pow2n=(1<<n);
      multiset<int> notchoose;
      multiset<int> choosed;
      
      rep0(i,pow2n){
            int s;
            cin>>s;
            notchoose.insert(-s);
      }
      notchoose.insert(1);
      auto itr=notchoose.begin();
      choosed.insert(*itr);
      notchoose.erase(itr);
      for(int i=0;i<n;i++){
            int pow2i=(1<<i);
            auto bitr=choosed.begin();
            auto eitr=choosed.end();
            vector<int> horyuu;
            for(auto itr=bitr;itr!=eitr;itr++){
                  ll pos=*itr;
                  auto korosu=notchoose.lower_bound(pos+1);
                  horyuu.push_back(*korosu);
                  notchoose.erase(korosu);
                  if(*korosu>0){
                        cout<<"No"<<endl;
                        return 0;
                  }
            }
        for(auto a:horyuu){
          choosed.insert(a);
        }
      }
      cout<<"Yes"<<endl;

      return 0;
}
