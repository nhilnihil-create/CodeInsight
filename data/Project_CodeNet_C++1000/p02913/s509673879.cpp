#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 1
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" ";
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

// Sparse Table
template<class MeetSemiLattice> struct SparseTable {
    vector<vector<MeetSemiLattice> > dat;
    vector<int> height;
    
    SparseTable() { }
    SparseTable(const vector<MeetSemiLattice> &vec) { init(vec); }
    void init(const vector<MeetSemiLattice> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1<<h));
        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = min(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
    }
    
    MeetSemiLattice get(int a, int b) {
        return min(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
    }
};


struct SuffixArray {
    string s;
    lli n, k;
    vector<lli> sa, tmp, rank_sa;
    vector<lli> lcp;
    SparseTable<lli> st;
  
    struct CompareSA {
      lli n, k;
      const vector<lli> &rank;
      CompareSA(lli n, lli k, const vector<lli> &rank_sa)
          : n(n), k(k), rank(rank_sa) {
      }
      bool operator()(lli i, lli j) {
        if(rank[i] != rank[j])
          return rank[i] < rank[j];
        else {
          lli rank_ik = (i + k <= n ? rank[i + k] : -1);
          lli rank_jk = (j + k <= n ? rank[j + k] : -1);
          return rank_ik < rank_jk;
        }
      }
    };
    SuffixArray(const string &S) {
      s = S;
      n = S.size();
      sa = vector<lli>(n + 1);
      rank_sa = vector<lli>(n + 1);
      tmp = vector<lli>(n + 1);
      lcp = vector<lli>(n + 1);
      createSuffixArray();
      createLCP();
    }
    void createSuffixArray() {
      for(lli i = 0; i <= n; i++) {
        sa[i] = i;
        rank_sa[i] = i < n ? (lli)s[i] : -1;
      }
  
      for(k = 1; k <= n; k *= 2) {
        CompareSA csa(n, k, rank_sa);
        sort(sa.begin(), sa.end(), csa);
  
        tmp[sa[0]] = 0;
        for(lli i = 1; i <= n; i++) {
          tmp[sa[i]] = tmp[sa[i - 1]];
          if(csa(sa[i - 1], sa[i])) tmp[sa[i]]++;
        }
        for(lli i = 0; i <= n; i++) {
          rank_sa[i] = tmp[i];
        }
      }
    }
    void createLCP(){
        REP(i,0,n+1)rank_sa[sa[i]] = i;

        lli h = 0;
        lcp[0]=0;
        REP(i,0,n){
            lli j = sa[rank_sa[i]-1];

            if(h>0)h--;
            for(;j+h<n && i+h<n;h++){
                if(s[j+h] != s[i+h])break;
            }
            lcp[rank_sa[i]-1] = h;
        }
        st.init(lcp);
    }
  bool contains(const string &t){
    lli l = 1;
    lli r = n+1;
    while(r - l > 1) {
      lli mid =(r+l)/ 2;
      lli index = sa[mid];
      lli cmp = s.compare(index, t.size(), t);
      if(cmp > 0)
        r = mid;
      else
        l = mid;
    }
    return s.compare(sa[l], t.size(), t) == 0;
  }
    void show(){
        REP(i,0,n+1)LOG3(s.substr(sa[i]),sa[i],lcp[i]);
    }
    // calc lcp
    int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
        return st.get(min(rank_sa[a], rank_sa[b]), max(rank_sa[a], rank_sa[b]));
    }

    set<lli> containsRange(const string &t){
      set<lli> rtn;
      lli outL,outR;
      {
        lli l = 1;
        lli r = n+1;
        while(r - l > 1) {
          lli mid =(r+l)/ 2;
          lli index = sa[mid];
          lli cmp = s.compare(index, t.size(), t);
          if(cmp > 0)
            r = mid;
          else
            l = mid;
        }
        outL = l;
      }
      {
        lli l = 0;
        lli r = n+1;
        while(r - l > 1) {
          lli mid =(r+l)/ 2;
          lli index = sa[mid];
          lli cmp = s.compare(index, t.size(), t);
          if(cmp < 0)
            l = mid;
          else
            r = mid;
        }
        
        outR = r;
      }
      LOG2(outR,outL);
      REP(i,outR,outL+1)rtn.insert(sa[i]);
      return rtn;
    }
  };


void func(long long N, std::string S){

    SuffixArray sa(S);

    lli ans=0;
    REP(i,0,N){
        for(lli j=i+1;j<N;j++){
            lli lcp = sa.getLCP(i,j);
            chmin(lcp,j-i);
            chmax(ans,lcp);
        }
    }

    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    func(N, S);
    return 0;
}
