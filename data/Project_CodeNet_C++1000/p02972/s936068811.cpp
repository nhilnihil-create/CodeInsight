#include <bits/stdc++.h>
using namespace std;

int a[200005];
int b[200005];
int main(){
  int n;
  cin >> n;
  int tmp;
  int ans;
  int count=0;
  for(int i=1;i<n+1;i++)cin >> a[i];
  for(int i=n;i>0;i--){
    tmp=i;
    ans=0;
    while(tmp<=n){
      ans+=b[tmp];
      tmp+=i;
    }
    if(ans%2!=a[i]){
      b[i]++;
      count++;
    }
  }
  cout << count << endl;
  for(int i=1;i<n+1;i++)if(b[i]>0)cout << i <<endl;
}
