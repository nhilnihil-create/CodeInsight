#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;

#define MOD 1000000007
#define INF 1000000
#define PI 3.14159265358979323846264338327950L
#define MAX 200010
#define lb lower_bound //[2,4)=lb(4)-lb(2);

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << end

/*
こういう問題あんまり好きじゃない・・・・
K=10^5なので操作して変更しながら数えるとかは不可能
つまり最初の条件ですぐ答えが出るということ・・・

一回の操作で増える幸福度に注目すると高々２であることがわかる
＋１・・・・端っこを含む場合
＋２・・・・端っこを含まない場合
*/

ll count_happy(string S)
{
  ll n = S.size();
  ll count=0;
  rep(i,n-1)
  {
    if (S[i]==S[i+1]) count++; 
  }
  return (count);
}

int main()
{
  ll N,K;cin>>N>>K;
  string S;cin>>S;
  
  ll count=0;
  ll flag=1;
  int i=0;
  while (i<N-1)
  {
    while (S[i]==S[i+1]) i++;
    if (S[i]=='R' && i!=N-1) count++;
    i++;
  }
  //cout<<count<<endl;
  
  ll ans = count_happy(S);
  if (count >= K) 
  {
    ans += 2*K;
    //cout<<"==="<<endl;
  }
  else
  {
    ans = N-1;
  }

  cout<<ans<<endl;
}