#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int N;
std::string S;

template<typename S>
void sa_is(S s, int B, std::vector<int>& sa, std::vector<int>& cnt) {
  int n = s.size();
  sa.resize(n+1);
  if(n == 0) return;
  
  for(auto& c: s) ++c; s.push_back(0);
  ++B;
  
  std::vector<bool> iss(n+1);
  std::vector<int> bin(B+1), lms, is_lms(n+1, -1);
  iss[n] = true;
  ++bin[1];
  for(int i = n-1; i >= 0; --i) {
    iss[i] = (s[i] == s[i+1])? iss[i+1]: (s[i] < s[i+1]);
    if(!iss[i] && iss[i+1]) {
      is_lms[i+1] = lms.size();
      lms.push_back(i+1);
    }
    ++bin[s[i]+1];
  }
  for(int i = 0; i < B; ++i) bin[i+1] += bin[i];
  auto induce = [&](std::vector<int>const& lms) {
    sa.assign(n+1, -1);
    cnt.assign(B, 0);
    for(auto x: lms) sa[bin[s[x]+1] - ++cnt[s[x]]] = x;
    std::fill(cnt.begin(), cnt.end(), 0);
    for(auto x: sa) if(--x >= 0 && !iss[x]) {
      sa[bin[s[x]] + cnt[s[x]]++] = x;
    }
    std::fill(cnt.begin(), cnt.end(), 0);
    for(int i = n; i >= 0; --i) {
      int x = sa[i]-1;
      if(x >= 0 && iss[x]) sa[bin[s[x]+1] - ++cnt[s[x]]] = x;
    }
  };
  induce(lms);
  int m = lms.size();
  if(m <= 1) return;
  std::vector<int> rec_lms; rec_lms.reserve(m);
  for(auto x: sa) if(is_lms[x] >= 0) rec_lms.push_back(x);
  int rec_n = 1;
  std::vector<int> rec_s(m);
  rec_s[m - 1 - is_lms[rec_lms[1]]] = rec_n;
  for(int i = 2; i < m; ++i) {
    int xl = rec_lms[i];
    int yl = rec_lms[i-1];
    int xr = lms[is_lms[xl]-1];
    int yr = lms[is_lms[yl]-1];
    if(xr-xl != yr-yl) ++rec_n;
    else while(xl <= xr) {
      if(s[xl] != s[yl]) { ++rec_n; break; }
      ++xl;
      ++yl;
    }
    rec_s[m - 1 - is_lms[rec_lms[i]]] = rec_n;
  }
  sa_is(std::move(rec_s), rec_n+1, sa, cnt);
  int li = m;
  for(int i = 1; i <= m; ++i) {
    rec_lms[--li] = lms[m - 1 - sa[i]];
  }
  induce(rec_lms);
}

template<typename S>
struct suffix_array {
  int n_;
  std::vector<int> sa, rank, lcp, cnt;
  suffix_array(S s, int B):
    n_(s.size()), rank(n_+1), lcp(n_) {
    sa_is(s, B, sa, cnt);
    for(int i = 0; i <= n_; ++i) rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for(int i = 0; i < n_; ++i) {
      int j = sa[rank[i]-1];
      if(h > 0) --h;
      for(; i+h < n_ && j+h < n_; ++h) if(s[j+h] != s[i+h]) break;
      lcp[rank[i] - 1] = h;
    }
  }
};

// suffix array
bool isOK(int l, std::vector<int>const& sa, std::vector<int>const& lcp) {
  int maxp = -1, minp = sa.size()+1;
  for(int i = 0; i+1 < sa.size(); ++i) {
    if(lcp[i] < l) { maxp = -1; minp = sa.size()+1; }
    else {
      maxp = std::max(maxp, sa[i]);
      minp = std::min(minp, sa[i]);
      if(abs(maxp - sa[i+1]) >= l) return true;
      if(abs(minp - sa[i+1]) >= l) return true;
    }
  }
  return false;
}

int main() {
  std::cin >> N >> S;
  std::vector<std::uint8_t> s(S.size());
  for(int i = 0; i < s.size(); ++i) s[i] = S[i] - 'a';
  suffix_array<std::vector<std::uint8_t>> sa(s, 26);
  
  int ok = 0, ng = N/2+1;
  while(ng - ok > 1) {
    int mid = (ok+ng)/2;
    if(isOK(mid, sa.sa, sa.lcp)) ok = mid; else ng = mid;
  }
  fin(ok);
  return 0;
}
