#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<n; i++){};
int main() {
int P,Q,R;
cin>>P>>Q>>R;
int A=P+Q;
int B=P+R;
int C=R+Q;
int g=min(A,B);
cout<<min(g,C)<<endl;
 }
