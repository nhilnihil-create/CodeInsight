#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i < (int)(n);i++)
typedef long long ll;

int main(){
  ll n,m;
  priority_queue <int> PQ;
  pair <int,int> a[100006];

  scanf("%lld %lld", &n ,&m);

  int i;
  for(i = 0;i < n;i++){
    scanf("%d %d", &a[i].first, &a[i].second);
  }

  sort(a,a + n);

  int j;

  j = 0;
  int t;
  ll ans = 0;

  for(i = 1;i <= m;i++){
    while(a[j].first == i){
      t = a[j].second;
      j++;
      PQ.push(t);
    }

    if(!(PQ.empty())){
      ans += PQ.top(); PQ.pop();
    }
  }

  printf("%lld\n", ans);

  return 0;
}
