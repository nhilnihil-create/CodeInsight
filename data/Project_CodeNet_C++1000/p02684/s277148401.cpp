

#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
//#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 int main(){
 int n,s,t=1,cnt=0;
  int64_t k;
  cin >> n >> k;
  int a[n+1],b[(1<<25)+1];

  for(int i=1;i<=n;i++)cin >> a[i];


  while(k--){
    t=a[t];
    if(b[t]) {
            k%=cnt-b[t];
            // cout<<k<<" "<<cnt<<" "<<b[t]<<endl;
    }
    b[t]=cnt++;
  }
  cout << t << endl;


 }
