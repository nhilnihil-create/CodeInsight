#include <iostream>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define p(i, n) for (z i = 0; i < n; i++)
using z=long long;
int main(){z N,Q;cin>>N>>Q;fenwick_tree<z> b(N);p(i,N){z a;cin>>a;b.add(i,a);}p(i,Q){z w,e,r;cin>>w>>e>>r;if(w)cout<<b.sum(e,r)<<"\n";else b.add(e,r);}}
