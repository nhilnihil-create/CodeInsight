#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#define ll long long
#define fr(i,k,N) for(decltype(N+k) i=k; i<N;i++)
#define rep(i,N) for(decltype(N) i=0; i<N;i++)
#define ALL(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it<<endl;}}
template <class X> void prrr(X test){int f=0;for(auto it:test){cout<<(f++!=0?" ":"")<<it;}cout<<endl;}
template<typename X>
istream&operator>>(istream&i,vector<X>&v){for(X&x:v)i>>x;return i;}

class UF { // union find from https://github.com/kartikkukreja/blog-codes (MIT)
    // [usage]
    // auto uf = new UF(n);
    // uf->merge(l, r); // 0 <= l, r <= n-1
    // ...
public:
    int *id; // inner id
    int cnt; // number of all vartices
    int *sz; // sz[i] means size of i's set
    UF(int N)   {
        cnt = N;
        id = new int[N];
        sz = new int[N];
        for(int i=0; i<N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF() {
        delete [] id;
        delete [] sz;
    }
    int find(int p) {
        int root = p;
        while (root != id[root]) root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    void merge(int x, int y) {
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        
        if (sz[i] < sz[j]) {
            id[i] = j;
            sz[j] += sz[i];
        } else {
            id[j] = i;
            sz[i] += sz[j];
        }
        cnt--;
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int count() {
        return cnt;
    }
};

// return 約数unordered_set 1 <= x <= n
auto divv = [](auto n) {
  unordered_set<decltype(n)> v;
  for(decltype(n) i = 1; i*i <= n; i++) {
    if(n%i == 0) {
      v.insert(i);
      if(i*i != n) v.insert(n/i);
    }
  }
  return v;
};

// check prime (and n>=2) or not
auto isPrime = [](auto n){
  if(n <= 1) return false;
  for(decltype(n) i = 2; i <= sqrt(n); ++i) {
      if(n % i == 0) {
          return false;
      }
  }
  return true;
};



int main() {
    ll t1,t2,a1,a2,b1,b2;
    cin>>t1>>t2;
    cin>>a1>>a2;
    cin>>b1>>b2;
    if(t1*a1+t2*a2 == t1*b1 + t2*b2){
        pr("infinity");
        return 0;
    }else if(t1*a1+t2*a2 < t1*b1 + t2*b2){
        swap(a1,b1);
        swap(a2,b2);
    }
    if(a1>b1) {
        pr(0);
        return 0;
    }
    auto y = b1 - a1;
    y*=t1;
    auto diff = t1*a1+t2*a2 - t1*b1 - t2*b2;
    if(y%diff != 0) pr(y/diff*2+1);
    else pr(y/diff*2);


}
