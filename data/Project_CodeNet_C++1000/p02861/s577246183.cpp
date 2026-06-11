#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int n;
  cin >> n;
  vector<pair<int,int>> a(n); 
  rep(i,n){
    int b,c;
    cin >> b >> c;
    a.at(i)=make_pair(b,c);
  }
  double ans=1,sum=0;
  sort(a.begin(),a.end());
  do{
    for(int i=0;i<n-1;i++){
      double q=a.at(i).first,r=a.at(i).second;
      double b=a.at(i+1).first,c=a.at(i+1).second;
      sum+=sqrt((q-b)*(q-b)+(r-c)*(r-c));
    }
  }while (next_permutation(a.begin(),a.end()));
  for(int i=1;i<=n;i++){
    ans*=i;
  }
  printf("%.10lf",sum/ans);
}