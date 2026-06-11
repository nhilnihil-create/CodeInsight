#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<P> arr;
  rep(i, n){
    cin >> a[i] >> b[i];
    arr.push_back(P(a[i], -1));
    arr.push_back(P(b[i], 1));
  }
  sort(arr.begin(), arr.end());
  int cnt=0, bend=0, ans=0;
  if(n%2==1){
    int middle=n/2;
    rep(i, 2*n){
      if(bend<middle+1 && -cnt+bend>=middle+1){
        ans+=arr[i].first-arr[i-1].first;
      }
      cnt+=arr[i].second;
      if(arr[i].second==1){
        bend++;
      }


    }
    ans++;
  } else {
    int middle1=n/2, middle2=n/2+1;
    int min1, min2, max1, max2;
    rep(i, 2*n){
      cnt+=arr[i].second;
      if(arr[i].second==1){
        bend++;
      }
      if(-cnt+bend==middle1 && arr[i].second==-1){
        min1=arr[i].first;
      }
      if(-cnt+bend==middle2 && arr[i].second==-1){
        min2=arr[i].first;
      }
      if(bend==middle1 && arr[i].second==1){
        max1=arr[i].first;
      }
      if(bend==middle2 && arr[i].second==1){
        max2=arr[i].first;
      }
    }
    ans=max1+max2-(min1+min2)+1;
  }
  cout << ans << endl;
  return 0;
}
