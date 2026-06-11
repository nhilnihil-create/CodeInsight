#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,k,a,d;
  cin>>n>>k;
  int nums [101];
  memset(nums,0,sizeof(nums));
  while(k--){
    cin>>d;
    while(d--){
        cin>>a;
        nums[a]++;
    }
  }
  int cnt = 0;
  for(int i=1;i<=n;i++){
    if(nums[i]==0){
        cnt++;
    }
  }
  cout<<cnt;
}
