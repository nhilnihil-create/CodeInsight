#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  int N;
  cin >> N;

  vector<vector<P>> B(N,vector<P>());
  REP(i,N){
    int A;
    cin >> A;
    REP(j,A){
      int x,y;
      cin >> x >> y;
      B[x-1].push_back(make_pair(i,y));
    }
  }

  int MAX = 0;
  REP(i,pow(2,N)){
    int x = i;
    int cnt = 0;
    vector<int> vec;
    REP(i,N){
      vec.push_back(x%2);
      if(x%2==1){
        cnt++;
      }
      x/=2;
    }
    int flag = 0;
    REP(i,N){
      if(vec.at(i)==0){
        for(auto p:B[i]){
          if(vec.at(p.first)==1&&p.second==1){
            flag=1;
          }
        }
      }else if(vec.at(i)==1){
        for(auto p:B[i]){
          if(vec.at(p.first)==1&&p.second==0){
            flag=1;
          }
        }
      }
    }
    if(flag==0){
      MAX=max(MAX,cnt);
    }
  }

  cout << MAX << endl;
}