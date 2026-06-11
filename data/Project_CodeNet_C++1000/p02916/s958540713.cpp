# include <bits/stdc++.h>
# define rep(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
# define reps(i, n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(int i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>0; --i)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
using namespace std;
using lint = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  vector<int> B(N+1);
  vector<int> C(N);
  rep(i,N) cin>>A.at(i);
  reps(i,N) cin>>B.at(i);
  reps(i,N-1) cin>>C.at(i);
  int sum=0;
  rep(i,N){
    int a=A.at(i);
    if(i>=1&&a==A.at(i-1)+1){
      sum+=(B.at(a)+C.at(A.at(i-1)));
    }
    else sum+=B.at(a);
  }   
  cout<<sum<<endl;


  
}