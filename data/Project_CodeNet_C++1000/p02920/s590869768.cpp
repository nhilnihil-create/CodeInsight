#include <cstdio>
#include <queue>
#include <algorithm>

int n;
int S[1<<18];
std::priority_queue<int> Q;
std::vector<int> buf;

int main(){
  scanf("%d",&n);
  for(int i=0;i<(1<<n);i++) scanf("%d",S+i);
  std::sort(S, S+(1<<n), std::greater<int>());
  int k = 0;
  for(int i=0;i<(1<<n);){
    int j = i;
    for(i++; S[i] == S[j]; i++) ;
    S[k++] = i-j;
  }
  Q.push((1<<(n+1))-1);
  for(int i=0;i<k;i++){
    if(Q.size() < S[i]){
      puts("No");
      return 0;
    }
    for(int j=0;j<S[i];j++){
      int t = Q.top();
      Q.pop();
      for(t>>=1;t;t>>=1){
        buf.push_back(t);
      }
    }
    for(int x: buf) Q.push(x);
    buf.clear();
  }
  puts("Yes");
  return 0;
}
