

#include <bits/stdc++.h>
#include <string.h>
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

 int n; cin>>n;
 vector<int>a(n),b(n);

  for(int i=0;i<n;i++)
      cin>>a[i]>>b[i];

  vector<pair<int,int>>v(n);

  for(int i=0;i<n;i++){
      v[i].first = a[i]+b[i];
      v[i].second = a[i]-b[i];
  }

  sort(v.begin(),v.end());

  int maxi = INT_MIN,cnt=0;

  for(int i=0;i<n;i++){
      if(maxi <= v[i].second){

         cnt++;
       maxi = v[i].first;
      }
  }

  cout<<cnt<<endl;

return 0;
}