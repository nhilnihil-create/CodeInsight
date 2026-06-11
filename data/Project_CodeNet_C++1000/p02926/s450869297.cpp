#include <bits/stdc++.h>
using namespace std;

int main(){
int N; cin >> N;
int x[N], y[N]; 
long double arg; vector< pair<long double, int> > s(N);
for(int i=0; i<N; i++){
  cin >> x[i] >> y[i]; arg=atan2(y[i], x[i]);
  s[i]=make_pair(arg, i);
}
sort(s.begin(), s.end());
long double X, Y, ans=0; int u;
for(int L=0; L<N; L++){ for(int R=L; R<L+N; R++){
 X=0; Y=0;
 for(int i=L; i<=R; i++){ u=s[i%N].second; X+=x[u]; Y+=y[u]; }
 ans=max(ans, sqrt(X*X+Y*Y));
}}
cout << setprecision(30) << ans << "\n";
}