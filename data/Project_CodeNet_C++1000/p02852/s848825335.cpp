#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;


struct SegmentTree {
        private:
        int n;
        vector<int> node;
        
        public:
        SegmentTree(vector<int> v){
                int sz = v.size();
                n = 1;
                while(n < sz) n *= 2;
                node.resize(2*n-1,INF);
                for(int i=0;i<sz;i++) node.at(i+n-1) = v.at(i);
                for(int i=n-2;i>=0;i--) node.at(i) = min(node.at(2*i+1),node.at(2*i+2));
        }
        
        //x番目の要素をvalに変更する。
        void update(int x,int val){
                x += n-1;
                node.at(x) = val;
                while(x > 0){
                        x = (x-1)/2;
                        node.at(x) = min(node.at(2*x+1),node.at(2*x+2));
                }
        }
        
        //区間[a,b)の最小値を求める
        int getmin(int a,int b,int k=0,int l=0,int r=-1){
                if(r < 0) r = n;
                if(r <= a || b <= l) return INF;
                if(a <= l && r <= b) return node.at(k);
                int vl = getmin(a,b,2*k+1,l,(l+r)/2);
                int vr = getmin(a,b,2*k+2,(l+r)/2,r);
                return min(vl,vr);
        }
};
 
int main() {
  int n,m;
  cin >> n >> m;
  string S;
  cin >> S;
  vector<int> dp(n+1,INF);
  SegmentTree seg(vector<int>(n+1,INF));
  dp.at(0) = 0;
  seg.update(0,0);
  for(int i=1;i<=n;i++){
    if(S.at(i) == '1') continue;
    int l = max(0,i-m);
    dp.at(i) = seg.getmin(l,i) + 1;
    seg.update(i,dp.at(i));
  }
  
  if(dp.at(n) >= INF){
    cout << -1 << endl;
    return 0;
  }
  
  vector<int> dice;
  int s = 0;
  int i = n;
  int j = n;
  int before = n;
  int now = dp.at(n)-1;
  while(i >= 0){
    if(dp.at(i) == now-1 || before - i > m){
      dice.push_back(before-j);
      s += before-j;
      before = j;
      j = i;
      now --;
    }else if(dp.at(i) == now){
      j = i;
    }
    i --;
  }
    
  dice.push_back(n-s);
  reverse(dice.begin(),dice.end());
  
  for(int i=0;i<dice.size();i++) cout << dice.at(i) << endl;  
  
  
  return 0;
}

