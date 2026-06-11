#include <iostream>
#include <atcoder/all>
using namespace std;int main(){int N,Q;cin>>N>>Q;atcoder::fenwick_tree<long> b(N);int n=N;while(n--){long a;cin>>a;b.add(N-1-n,a);}while(Q--){int w,e,r;cin>>w>>e>>r;if(w)cout<<b.sum(e,r)<<endl;else b.add(e,r);}}