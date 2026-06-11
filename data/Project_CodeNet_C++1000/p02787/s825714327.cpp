#include <iostream>
using namespace std;
int hp,n;
int atk[1001];
int cost[1001];
int mem[10001];
//int temp[10000];
int templen=0;
int f(int hp){
  if (hp<=0&&hp!=-99999) return 0;
  if (mem[hp]>0) return mem[hp];
  
  int minn=99999999+99999999;
  for (int i=0;i<n;i++){
    if (hp>0){
      int x=f(hp-atk[i])+cost[i];
      //temp[templen]=i;
      //templen++;
      if (x<minn) minn=x;
      //if (hp-atk[i]<=0) cout<<minn<<endl;
    }//else cout<<minn<<endl;
  }

  mem[hp]=minn;
  return minn;
}
int main() {
  
  cin>>hp>>n;
  for (int i=0;i<n;i++){
    cin>>atk[i]>>cost[i];
  }
  mem[0]=0;
  for (int i=1;i<10001;i++){  
    mem[i]=-99999;  
  }  
  /*
  int maxn=0,ind;
  for(int i=0;i<n;i++){
    if(atk[i]/cost[i]>maxn) {
      maxn=atk[i]/cost[i];
      ind=i;
    }
  }
  */

  /*
  if (hp>=100){
    int y=hp*0.1;
    while(hp>=y){
      hp-=atk[ind];
      mp+=cost[ind];
      //cout<<"#";
    }
  }
  */
  //cout<<"ind "<<ind<<endl;
  //for (int i=0;i<=hp;i++){  
    //cout<<i<<"  "<<mem[i]<<endl;
  //}  
  cout<<f(hp)<<endl;
}