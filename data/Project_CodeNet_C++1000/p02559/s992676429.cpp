#include <iostream>
#include <atcoder/all>
using namespace std;using z=long;int main(){z N,Q;cin>>N>>Q;atcoder::fenwick_tree<z> b(N);for(z i=0;i<N;i++){z a;cin>>a;b.add(i,a);}for(z i=0;i<Q;i++){z w,e,r;cin>>w>>e>>r;if(w)cout<<b.sum(e,r)<<endl;else b.add(e,r);}}