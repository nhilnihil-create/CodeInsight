


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
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007
//#define N 12
#define sz 1000*1000

 int main(){

 int n; cin>>n;
  vector<pair<int,int>>v(n);

  for(int i=0;i<n;i++){
   cin>>v[i].second>>v[i].first;
  }

  sort(v.begin(),v.end());

  int sum =0;
  bool ans = true;

  for(vector<pair<int,int>>::iterator it = v.begin();it!=v.end();it++)
  {
      sum += it->second;
      if(sum > it->first){
            ans = false;
            break; }
  }

  if(ans == false)
      cout<<"No"<<endl;
  else
      cout<<"Yes"<<endl;

 return 0;
 }
