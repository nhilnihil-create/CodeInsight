#include <bits/stdc++.h>
using namespace std;

int main(){
  long n, k;  cin >> n >> k;
  vector<long> p(n+1, 0), c(n+1, 0);
  for(int i=1; i<=n; i++)  cin >> p[i];
  for(int i=1; i<=n; i++)  cin >> c[i];

  vector<vector<long>> route(n+1);
  vector<vector<long>> score(n+1); 
  for(int s=1; s<=n; s++){ // start
    long now = s;
    vector<bool> seen(n+1, false);
    while(seen[p[now]] == false){
      route[s].push_back(p[now]);
      seen[p[now]] = true;
      score[s].push_back(c[p[now]]);
      now = p[now];
    }
  }

  long ans = score[1][0];
  for(int i=1; i<=n; i++){
    long ssum = score[i][0], len = score[i].size();
    long maxtok = score[i][0], maxtofull = score[i][0];
    for(int j=1; j<len; j++){
      ssum += score[i][j];
      maxtofull = max(maxtofull, ssum);
      if(j < (k%len))
	maxtok = max(maxtok, ssum);
    }
    //    printf("ssum:%ld  maxtok:%ld\n", ssum, maxtok);
    if(k < len){
      ans = max(ans, maxtok);
    }else if(ssum < 0){
      ans = max(ans, maxtofull);
    }else{
      //printf("zen:%ld  mae:%ld\n", ssum*(long)(len/k)+maxtok, ssum*(long)(len/k-1)+maxtofull);
      if(k%len == 0)  maxtok = 0;
      ans = max(ans, ssum*(long)(k/len)+maxtok);
      ans = max(ans, ssum*(long)(k/len-1)+maxtofull);
    }
  }

  cout << ans << endl;
  
  return 0;
}
  
