#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);++i)
#define fi first
#define se second
#define INF 1000000009
#define lINF 1000000000000000009
typedef long long ll;
int n;
int a[300009];
int s[300009];

bool judge(ll mid,ll k){
  int idx=upper_bound(a,a+n,mid)-a;
  ll sum=s[idx]+mid*(n-idx);
  if(sum>=mid*k)return 1;
  else return 0;
}

int main(){
  cin>>n;
  rep(i,n){
    int x;
    cin>>x;
    a[x-1]++;
  }
  sort(a,a+n);
  for(int i=0;i<n;i++){
    s[i+1]=s[i]+a[i];
  }

  for(int i=1;i<=n;i++){
    int left=-1,right=n+1;
    while(right-left>1){
      ll mid=(left+right)/2;
      if(judge(mid,i)){
        left=mid;
      }
      else{
        right=mid;
      }
    }
    cout<<left<<endl;
  }

  return(0);

}
