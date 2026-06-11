#include<bits/stdc++.h>
using namespace std;int N,i,v,k;char c;main(){for(cin>>N,N--;i<=N;cin>>c,v+=((N&i)==i)*(c-1),k+=c&1,i++);v&=3;cout<<(v&1?1:k<N?0:v);}