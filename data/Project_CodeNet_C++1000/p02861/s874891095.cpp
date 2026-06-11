#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<pair<int,int>> v(n);
  double sum=0;
  rep(i,n)cin>>v[i].first>>v[i].second;

  int count=0;
  sort(v.begin(),v.end());

  do{
    rep(i,n-1){
      sum+=sqrt((v[i].first-v[i+1].first)*(v[i].first-v[i+1].first)+(v[i].second-v[i+1].second)*(v[i].second-v[i+1].second));
    }
    count++;
  }while(next_permutation(v.begin(),v.end()));

  printf("%.7lf\n",sum/count);
  return 0;
}
