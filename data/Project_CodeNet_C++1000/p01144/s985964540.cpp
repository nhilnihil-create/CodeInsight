#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int main(){
  int n,money;
  while(cin >>n>>money &&( n>0||money>0)){
    pair<int,int> PD[10010];
    int p,d;
    for(int i=0;i<n;i++){
      cin >>d>>p;
      PD[i]=make_pair(p,d);
    }

    sort(PD,PD+n);
    int need;
    int ans=0;
    for(int i=0;i<n;i++){
      need=i;
      if(PD[n-1-i].second<=money){
	money-=PD[n-1-i].second;
      }else{
	ans+=PD[n-1-i].first*(PD[n-1-i].second-money);
	break;
      }
    }
    
    for(int j=0;j<n-1-need;j++){
      ans+=PD[j].first*PD[j].second;
    }
    cout << ans <<endl;
  }
}  