#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;	cin >> n;
  vector<int>	L(n);
  for(int i=0;i<n;i++)	cin >> L[i];
  
  sort(L.begin(),L.end());
  int ans=0;
  for(int a=0;a<n;a++){
    for(int b=a+1;b<n;b++){
      int left=b+1;
      int right=lower_bound(L.begin(),L.end(),L[a]+L[b])-L.begin();
      ans+=right-left;
    }
  }
  cout << ans;
}