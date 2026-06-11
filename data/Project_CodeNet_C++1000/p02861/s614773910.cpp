
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

  int n;
  int mm = 0;
  cin>>n;

  vector<pair<double,double>> vec(n);
  vector<int>perm(n);

  for(int i=0;i<n;i++)
    cin>>vec[i].first>>vec[i].second;

  iota(perm.begin(),perm.end(),0);
  double dist=0;

  do{
    mm++;
    for(int i=1;i<n;i++){
        dist += sqrt(pow(vec[perm[i]].first-vec[perm[i-1]].first,2) +
                     pow(vec[perm[i]].second - vec[perm[i-1]].second,2));

    }
  }while(next_permutation(perm.begin(),perm.end()));

  cout<<fixed<<setprecision(10);

  cout<<dist/mm<<endl;



return 0;
}
