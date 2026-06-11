#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
using namespace std;
template<class A>void pr(A a){cout << a << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;p(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;p(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;p(b,c,d);}
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
int INF=numeric_limits<int>::max();
// for(int j=0;j<N;++j) {}

int main(void) {
  int a;cin>>a;
  string s;cin>>s;
  if(a>=3200) {
    pr(s);
  } else {
    pr("red");
  }
  return 0;
}
