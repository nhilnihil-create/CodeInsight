#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N,K,C;
  string S;
  cin >> N >> K >> C >> S;

  vector<int> suml(N+1,0);
  vector<int> sumr(N+1,0);
  for(int i=0;i<N;i++){
    if(S.at(i)=='x')  continue;
    suml.at(i+1)=1;
    i+=C;
  }
  for(int i=0;i<N;i++)  suml.at(i+1)+=suml.at(i);
  for(int i=N-1;i>=0;i--){
    if(S.at(i)=='x')  continue;
    sumr.at(i)=1;
    i-=C;
  }
  for(int i=N-1;i>=0;i--)  sumr.at(i)+=sumr.at(i+1);

  for(int i=0;i<N;i++){
    if(S.at(i)=='x')  continue;
    int tmp=suml.at(i)+sumr.at(i+1);
    if(tmp<K) cout << i+1 << endl;
  }

  return 0;
}