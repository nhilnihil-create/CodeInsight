#include <bits/stdc++.h>
using namespace std;
#define	rep(i,n)	for(int i=0;i<n;i++)
int main(){
  int n;	cin >> n;
  vector<pair<long long,long long>>	ab(n);
  rep(i,n)	cin >> ab[i].second >> ab[i].first;
  sort(ab.begin(),ab.end());
  
  long long time=0;
  rep(i,n){
    time+=ab[i].second;
    if(ab[i].first<time){
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
}