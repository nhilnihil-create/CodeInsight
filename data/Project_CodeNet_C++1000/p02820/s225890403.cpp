#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, k, n) for (int i = k; i < (int)(n); i++)
#define repd(i, n) for (int i = n-1; i >= 0; i--)
#define rrepd(i, k, n) for (int i = n-1; i >= (int)(k); i--)
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素
#define PB push_back //挿入
#define MP make_pair //pairのコンストラクタ
//V,Pは大文字i,l,bは小文字
using ll = long long;
using Vi = vector<int>;
using VVi = vector<Vi>;
using Vl = vector<ll>;
using VVl = vector<Vl>;
using Vb = vector<bool>;
using VVb = vector<Vb>;
using P = pair<int,int>;
using Pll = pair<ll, ll>;
const ll mod = 1000000007;
const ll inf = 1000000000000;//10の12乗

int main() {
  int n,k;
  cin >> n >> k;
  int p,r,s;
  cin >> r >> s >> p;
  string t;
  cin >> t;
  ll pt=0;
  int rc=0,sc=0,pc=0;
  Vb win(t.size(),0);
  rep(i,t.size()){
    char c=t[i];
    if(i<k){
      if(c=='r') pt+=p;
      else if(c=='s') pt+=r;
      else pt+=s;
      win[i]=1;

    }
    else{
      if(t[i-k]!=t[i]||win[i-k]==0){
        if(c=='r') pt+=p;
        else if(c=='s') pt+=r;
        else pt+=s;
        win[i]=1;

      }
    }
  }
  cout << pt << endl;
      
}