#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

#define vi vector<int>

int main(){
  int i,j;
  int h,w;
  pair<int,pair<int,int> > p[22500];
  int n=0;
  for(i=1;i<=150;i++)
    for(j=i+1;j<=150;j++){
      p[n].first=i*i+j*j;
      p[n].second.first=i;
      p[n].second.second=j;
      n++;
    }
  sort(p,p+22500);
  while(1){
    cin>>h>>w;
    if(h==0&&w==0)break;
    for(i=0;i<22500;i++)
      if(p[i].second.first==h && p[i].second.second==w){
        cout<<p[i+1].second.first<<" "<<p[i+1].second.second<<endl;
        break;
      }
  }
}