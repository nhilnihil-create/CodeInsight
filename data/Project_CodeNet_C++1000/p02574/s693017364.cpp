#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define All(a) (a).begin(),(a).end()

vector<int> X(1000001);

ll gcd(ll a,ll b){
  b%=a;
  if(b==0)return a;
  else gcd(b,a);
}



void solve(){
  int n,m;
  scanf("%d",&n);
  vector<int> A(n);
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
    X[A[i]]++;
  }
  sort(All(A));

  int tmp=A[0];
  for (int i = 1; i < n; i++)
  {
    tmp=gcd(tmp,A[i]);
  }
  if(tmp>1){ 
    printf("not coprime\n");
    return;
  }

  for (int i = 2; i <  1000001; i++){
    int cnt=0;
    for (int j = i; j <1000001; j+=i)
    {
      cnt+=X[j];
    }
      if(cnt>1){
        printf("setwise coprime\n");
        return;
      }
      //auto a=find(All(X),f[j]);
      //if(a!=X.end())goto setwise;
      //else{
      //X.push_back(f[j]);
      //}
    
    
  }
  printf("pairwise coprime\n");
  return;
}
int main(){
  
  // int q=3;
  // while(q--){
  //   solve();
  // }
 solve();
  return 0;
}