#include <cstdio>
#include <algorithm>
#include <functional>

int n;
int S[1<<18];
int Q[19];


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
  Q[n] = 1;
  for(int i=0;i<k;i++){
    int l;
    int a=0;
    for(l=n;l>=0 && a < S[i];l--) a += Q[l];
    if(a<S[i]){
      puts("No");
      return 0;
    }
    l++;
    for(int t=0;t<l;t++) Q[t] += S[i];
    int b = a-Q[l];
    Q[l] = a-S[i]+b;
    for(n=l+1;b;n++){
      b -= Q[n];
      Q[n] = b;
    }
    n--;
  }
  puts("Yes");
  return 0;
}
