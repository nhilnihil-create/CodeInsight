#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,n) for(int i=1;i<=n;i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define EPS (1e-9)
#define INF (1e17)
#define PI (acos(-1))
//const double PI = acos(-1);
//const double EPS = 1e-15;
//long long INF=(long long)1E17;
#define i_7 (long long)(1e9+7)
//#define i_7 998'244'353
long mod(long a){
    long long c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
long long po(long a, long b){
    if(b==0){
        return 1;
    }
    
    long long z = po(a,b/2);
    z = mod(z*z);
    if(b%2!=0){
        z = mod(a*z);
    }
    return z;
}
 
bool prime_(int n){
  if(n==1){
    return false;
  }else if(n==2){
    return true;
  }else{
    for(int i=2;i<=std::sqrt(n);i++){
      if(n%i==0){
        return false;
      }
    }
    return true;
  }
}
 
long long gcd_(long long a, long long b){
  if(a<b){
    std::swap(a,b);
  }
  if(a%b==0){
    return b;
  }else{
    return gcd_(b,a%b);
  }
}
 
long long lcm_(long long x, long long y){
  return (x/gcd_(x,y))*y;
}
 
//using namespace std;
//using namespace boost::multiprecision;
//using namespace __gnu_pbds;

int main(){
  using namespace std;
  int n;
  cin>>n;
  int A[n][n - 1];
  REP(i, n) REP(j, n - 1) cin>>A[i][j];
  
  stack<int> a[n];
  REP(i, n) for(int j = n - 2; j >= 0; j--) a[i].push(A[i][j] - 1);
  
  typedef pair<int, int> P;
  vector<P> battles; //現時点で実行可能な試合たち
  auto add_battle = [&a](int i, vector<P>& next_battles) -> void {
    if(a[i].empty()) return;
    int j = a[i].top();
    if(a[j].top() == i){
      if(i < j){
        next_battles.push_back(P(i, j));
      }else{
        next_battles.push_back(P(j, i));
      }
    }
    return;
  };
  REP(i, n) add_battle(i, battles);
  sort(ALL(battles)); battles.erase(unique(ALL(battles)), battles.end());
  
  int days = 0;
  while(!battles.empty()){
    days++;
    for(auto& battle: battles){
      int i = battle.first, j = battle.second;
      a[i].pop(); a[j].pop();
    }
    vector<P> next_battles;
    for(auto& battle: battles){
      int i = battle.first, j = battle.second;
      add_battle(i, next_battles);
      add_battle(j, next_battles);
    }
    swap(battles, next_battles);
    sort(ALL(battles)); battles.erase(unique(ALL(battles)), battles.end());
  }
  
  REP(i, n){
    if(!a[i].empty()){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << days << endl;
    
  return 0;
}
