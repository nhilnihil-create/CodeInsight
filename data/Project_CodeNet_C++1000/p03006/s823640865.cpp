#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 2500;
typedef pair<int,int> P;
int main()
{
  int n,x,y,t=0,i,j,k=0,res=0;
  P pp=P(0,0);
  P xy[N_MAX],p[N_MAX];
  cin >> n;
  if(n==1){
    cout << "1" << endl;
    return 0;
  }
  for(i=0;i<n;i++)
    cin >> xy[i].first >> xy[i].second;
  for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++){
      p[k]=P(xy[i].first-xy[j].first,xy[i].second-xy[j].second);
      k++;
      p[k]=P(-p[k-1].first,-p[k-1].second);
      k++;
    }
  sort(p,p+k);
  for(i=0;i<k;i++)
    if(p[i]==pp){
      t++;
    }else{
      res=max(t,res);
      t=1;
      pp=p[i];
    }
  res=n-res;
  cout << res << endl;
  return 0;
}