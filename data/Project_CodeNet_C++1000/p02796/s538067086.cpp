#include<bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
int n;
int x[100000],l[100000];
void in(void){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x[i]>>l[i];
  }
}
P p[100000];
int leadS(void){
  for(int i=0;i<n;i++){
    p[i]=P(x[i]+l[i],x[i]-l[i]);
  }
  sort(p,p+n);
  int num=-1000000000;
  int ans=0;
  for(int i=0;i<n;i++){
    if(num<=p[i].second){
      ++ans;
      num=p[i].first;
    }
  }
  return ans;
}
int main(void){
  in();
  int ans=leadS();
  cout<<ans<<endl;
  return 0;
}