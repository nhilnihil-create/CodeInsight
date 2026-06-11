#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;


//基本的に勝つ手をだす．
//勝つ手がなければ，K回後に勝つ手以外を出す．

int main(){
  ll n,k,pr,ps,pp;
  cin>>n>>k>>pr>>ps>>pp;
  string t;
  cin>>t;
  vector<char> out(2*n+1);//i回目に出せない手
  ll ans=0;

  rep(i,n){
    out[i]='e';//未定
    t.push_back('e');

  }

  rep(i,n){
    switch(t[i]){
      case 'r':
        if(out[i]=='p'){//pを出せない時
          if(t[i+k]=='s'){//k回後がsの場合，sを出す．
            out[i+k]='s';
          }else{//t[i+k]=p or r　-> rを出す
            out[i+k]='r';
          }
        }else{
          out[i+k]='p';
          ans+=pp;
        }
        break;
      case 's':
        if(out[i]=='r'){
          if(t[i+k]=='p'){
            out[i+k]='p';
          }else{
            out[i+k]='s';
          }
        }else{
        out[i+k]='r';
        ans+=pr;
        }
        break;

      case 'p':
        if(out[i]=='s'){
          if(t[i+k]=='r'){
            out[i+k]='r';
          }else{
            out[i+k]='p';
          }
        }else{
          out[i+k]='s';
          ans+=ps;
        }


        break;

    }

  }

  cout<<ans<<endl;




  return 0;
}
