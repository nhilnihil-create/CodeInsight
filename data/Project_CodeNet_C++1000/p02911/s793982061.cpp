#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
int main(){int n,k,q; cin>>n>>k>>q; if(q<k){rep(i,n)cout<<"Yes"<<endl; return 0;}vector<int> p(n,0);rep(i,q){int a;cin>>a,a--,p[a]++;}rep(i,n)cout<<((p[i]<=q-k)?"No":"Yes")<<endl;}