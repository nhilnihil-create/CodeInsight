#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;	cin >> n >> k;
  vector<double> p(n);
  for(int i=0;i<n;i++){
    double per;	cin >> per;
    p.at(i)=(per+1)/2;
  }
  
  double sum=0;
  double ans=-1;
  queue<double>	que;
  for(double x:p){
    que.push(x);
    sum+=x;
    if(que.size()==k+1){
      sum-=que.front();
      que.pop();
    }
    ans=max(ans,sum);
  }
  printf("%.7f",ans);
}