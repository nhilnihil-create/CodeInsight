#include <iostream>
#include <atcoder/all>
using namespace std;using z=long;z N,Q,i,a,w,e,r;int main(){cin>>N>>Q;atcoder::fenwick_tree<z> b(N);for(;i<N;i++){cin>>a;b.add(i,a);}while(Q--){cin>>w>>e>>r;if(w)cout<<b.sum(e,r)<<endl;else b.add(e,r);}}