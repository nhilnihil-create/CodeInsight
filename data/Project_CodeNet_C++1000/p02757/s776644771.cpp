#include <bits/stdc++.h>
using namespace std;
int main(){
long N, P; string S; cin >> N >> P >> S;
long i, ans=0;
if(P==2||P==5){ 
  for(i=0; i<N; i++){ if((S[i]-'0')%P==0){ ans+=(i+1); } }
  cout << ans << "\n"; return 0;
}
long c=0, t=1; vector<long> R(N+1);
for(i=N-1; i>=0; i--){ R[i]=(t*(S[i]-'0')+R[i+1])%P; t=(10*t)%P; }
sort(R.begin(), R.end());
for(i=0; i<=N; i+=c, c=0){
  while(i+c<=N&&R[i]==R[i+c]){ c++; }
  ans+=c*(c-1)/2;
}
cout << ans << "\n"; return 0;
}