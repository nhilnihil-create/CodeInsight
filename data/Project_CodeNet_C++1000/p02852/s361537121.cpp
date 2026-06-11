#include <bits/stdc++.h>
using namespace std;
int main(){
int N, M, i, j; string S; cin >> N >> M >> S;
vector<int> ans;
for(i=N; i>0; i-=j){
for(j=M; j>0; j--){ 
  if(i-j<0||S[i-j]=='1'){ continue; }
  else{ ans.push_back(j); break; }
}
if(j==0){ cout << -1 << "\n"; return 0; }
}
for(i=ans.size(); i>0; i--){ cout << ans[i-1] << " "; }
cout << "\n";
}