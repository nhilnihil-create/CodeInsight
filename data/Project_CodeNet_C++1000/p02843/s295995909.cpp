#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int x;
  cin >> x;

  int q=x/100;
  int r=x%100;

  int ans=0;
  rep(i,x/100){
    if(q==0)break;
    
    if(r/5>=1)r-=5;
    else if(r/4>=1)r-=4;
    else if(r/3>=1)r-=3;
    else if(r/2>=1)r-=2;
    else if(r>=1)r-=1;

    q--;
		   
    if(r==0){
      ans=1;
      break;
    }
  }
  cout << ans << endl; 
}