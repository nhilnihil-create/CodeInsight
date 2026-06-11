#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;

class SuffixArray {
  int N;
  std::string str;
  std::vector<int> rank;
  std::vector<int> sa;
  std::vector<int> lcp;
  struct Comp {
    int N;
    int k;
    std::vector<int>* rank;
    bool operator()(int i, int j){
      if((*rank)[i] != (*rank)[j]) return (*rank)[i] < (*rank)[j];
      int ri = (i+k <= N ? (*rank)[i+k] : -1);
      int rj = (j+k <= N ? (*rank)[j+k] : -1);
      return ri < rj;
    }
  };
public:
  SuffixArray(std::string str):str(str),N(str.length()),sa(N+1),rank(N+1),lcp(N+1){}
  //O(N log^2 N)
  void build_sa(){
    std::vector<int> tmp(N+1);
    for(int i=0; i<=N; i++){
      sa[i] = i;
      rank[i] = (i < N ? str[i] : -1);
    }
    Comp comp;
    comp.N = N;
    comp.rank = &rank;
    for(int k=1; k<=N; k*=2){
      comp.k = k;
      std::sort(sa.begin(), sa.end(), comp);
      tmp[sa[0]] = 0;
      for(int i=1; i<=N; i++){
        tmp[sa[i]] = tmp[sa[i-1]] + (comp(sa[i-1], sa[i]) ? 1 : 0);
      }
      for(int i=0; i<=N; i++){
        rank[i] = tmp[i];
      }
    }
  }
  std::vector<int> get_sa(){
    return sa;
  }
  //O(N)
  void build_lcp(){
    for(int i=0; i<=N; i++) rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i=0; i<N; i++){
      int j = sa[rank[i]-1];
      if(h>0) h--;
      for(; j+h<N && i+h<N; h++){
        if(str[j+h] != str[i+h]) break;
      }
      lcp[rank[i]-1] = h;
    }
  }
  std::vector<int> get_lcp(){
    return lcp;
  }
  //O(|T|+|S|)
  bool contain(const std::string& query){
    int a=0, b=N;
    while(b-a>1){
      int c=(a+b)/2;
      if(str.compare(sa[c], query.length(), query) < 0) a = c;
      else b = c;
    }
    return str.compare(sa[b], query.length(), query) == 0;
  }
};

int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  SuffixArray sa(S);
  sa.build_sa();
  sa.build_lcp();
  vector<int> v = sa.get_sa();
  vector<int> h = sa.get_lcp();

  int ret = 0;
  REP(i,1,v.size()-1){
    vector<int> tmp;
    int j=i;
    tmp.push_back(v[i]);
    while(j<h.size() && h[i] <= h[j]){
      tmp.push_back(v[j+1]);
      j++;
    }
    sort(ALLOF(tmp));
    int x = h[i];
    int y = tmp[tmp.size()-1] - tmp[0];    
    ret = max(ret, min(x, y));

    //cout << v[i] << " " << h[i] << " " << tmp[tmp.size()-1] << " " << tmp[0] << endl;
  }

  cout << ret << endl;
  
  return 0;
}

