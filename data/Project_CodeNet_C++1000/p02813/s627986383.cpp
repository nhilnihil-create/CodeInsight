#include <bits/stdc++.h>
using namespace std;

int facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

void solve(){
  int n,m,x,count=0,r[2];
  scanf("%d",&n);
  int a[2][n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&a[0][i]);
  }
  
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&a[1][i]);
  }

  vector<int> v;
  for(int i=0;i<2;i++){
    r[i]=1;
    for (int i = 1; i <= n; i++)
      {
        v.push_back(i);
    }
    for(int j=0;j<n;j++){
      auto x=find(v.begin(),v.end(),a[i][j]);
      int a=distance(v.begin(),x);
      r[i]+=facctorialMethod(v.size()-1)*a;
      v.erase(x);
    }
  //printf("%d\n",r);
  }
  printf("%d",abs(r[0]-r[1]));



 //printf("%d\n",count);
}
int main(){
  /*
  int q;
  scanf("%d",&q);
  while(--q)solve();
  */
  solve();

  return 0;
}