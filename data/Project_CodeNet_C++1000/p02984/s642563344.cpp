#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int m=1000000007;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  ll sum=0;
  rep(i,n) sum+=a[i];
  int m=(n-1)/2;
  for(int i=1;i<n;i+=2){
    sum-=a[i]*2;
  }
  sum/=2;
  cout << sum*2 << "\n";
  for(int i=0;i<n-1;i++){
    sum=(a[i]-sum);
    cout << sum*2 << "\n";
  }
  
  return 0;
}