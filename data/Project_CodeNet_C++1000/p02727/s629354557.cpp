#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
  LL X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  deque<LL> p(A), q(B), r(C);
  for(auto v: {&p, &q, &r}) {
    for(auto& i: *v) cin >> i;
    sort(rbegin(*v), rend(*v));
  }
  multiset<LL> R, G;
  for(auto i=0; i<min(X,A); ++i) R.emplace(p[i]);
  for(auto i=0; i<min(Y,B); ++i) G.emplace(q[i]);
  for(auto i=R.size(); i<X; ++i) R.emplace(r.front()), r.pop_front();
  for(auto i=G.size(); i<Y; ++i) G.emplace(r.front()), r.pop_front();
  while(!r.empty()) {
    auto& l=R;
    auto& h=G;
    if(*begin(l) > *begin(h)) swap(l, h);
    if(r.front() <= *begin(l)) break;
    l.erase(begin(l));
    l.emplace(r.front());
    r.pop_front();
  }
  cout << accumulate(begin(R), end(R), 0ll) + accumulate(begin(G), end(G), 0ll) << endl;
}
