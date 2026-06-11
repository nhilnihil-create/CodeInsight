#include<atcoder/dsu>
#include<iostream>
int main(){int N,Q,t,u,v,q=0;std::cin>>N>>Q;atcoder::dsu d(N);for(;q<Q;q++){std::cin>>t>>u>>v;if(t)std::cout<<d.same(u,v)<<std::endl;else d.merge(u,v);}}