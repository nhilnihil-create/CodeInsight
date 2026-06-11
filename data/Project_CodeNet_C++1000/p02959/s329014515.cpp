
#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

 int main(){

  long long n;
  cin>>n;

  vector<int>A(n+1);
  for(int i=0;i<n+1;i++)
    cin>>A[i];

  vector<int>B(n);

  for(int i=0;i<n;i++)
    cin>>B[i];

  long long ans=0;
  for(int i=0;i<n;i++)
 {
    long long tmp = min(A[i],B[i]);
    A[i] -= tmp;
    B[i] -= tmp;
    ans += tmp;
 // cout<<ans<<" ? "<<tmp<<endl;
    tmp = min(A[i+1],B[i]);
    A[i+1] -= tmp;
    B[i] -= tmp;
    ans += tmp;

    //cout<<ans<<" > "<<tmp<<endl;

  }

  cout<<ans<<endl;

 return 0;
 }
