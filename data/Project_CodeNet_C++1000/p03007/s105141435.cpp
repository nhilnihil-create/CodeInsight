#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define VIEW(x) do {cerr << #x << ": "; for(auto i : x) cerr << i << " "; cerr << endl;} while(0)
#define ALL(x) (x).begin(),(x).end()
template<class T>bool umax(T &a, const T &b) {if(a<b){a=b;return 1;}return 0;}
template<class T>bool umin(T &a, const T &b) {if(b<a){a=b;return 1;}return 0;}

template<typename A,size_t N,typename T> void FILL(A (&array)[N],const T &val){fill((T*)array,(T*)(array+N),val);}
template<typename T> void FILL(vector<T> &v, const T &x) {fill(v.begin(), v.end(), x);}
template<typename T> void FILL(vector<vector<T>> &v, const T &x) {for(auto &i:v)fill(i.begin(), i.end(), x);}

int main() {
  int n; cin >> n;
  int z=0, p=0, m=0;

  multiset<int> a;
  int s = 0;
  rep(i,n) {
    int ai; cin >> ai;
    if(ai==0) z++;
    if(ai>0) p++;
    if(ai<0) m++;
    s+=abs(ai); 
    a.insert(ai);
  }

  if(m==n) {
    s += 2 * (*a.rbegin());
    cout << s << endl;
    int c = *a.rbegin();
    a.erase(prev(a.end()));
    while(a.size()) {
      cout << c << " " << *a.begin() << endl;;
      c -= *a.begin();
      a.erase(a.begin());
    }
    return 0;
  }
  if(p==n) {
    s -= 2 * (*a.begin());
    cout << s << endl;
    int c = *a.begin();
    a.erase(a.begin());
    while(a.size()>1) {
      cout << c << " " << *a.begin() << endl;
      c -= *a.begin();
      a.erase(a.begin());
    }
    cout << *a.begin() << " " << c << endl;
    return 0;
  }

  cout << s << endl;
  int c = *a.begin();
  a.erase(a.begin());
  while(p>1) {
    cout << c << " " << *a.rbegin() << endl;
    c -= *a.rbegin();
    a.erase(prev(a.end()));
    p--;
  }
  a.insert(c);
  c = *a.rbegin();
  a.erase(prev(a.end()));
  while(a.size()) {
    cout << c << " " << *a.begin() << endl;
    c -= *a.begin();
    a.erase(a.begin());
  }
}
