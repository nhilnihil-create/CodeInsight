#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

//オーダーやばそう、tn?

int main(){
  int n;
  cin >> n;
  int w[n];
  rep(i,n){cin>>w[i];}
  
  int ABS = 0; //s1とs2の差(絶対値)
  rep(t,n){
    int s1=0,s2=0;
    for(int i = 0; i < t; i++){ //区切りの前半
      s1 += w[i];
    }
    
    for(int j = t; j < n; j++){ //区切りの後半
      s2 += w[j];
    }
    if(t==0){
      ABS = abs(s1-s2);
    }else{
      if(ABS > abs(s1-s2)) ABS = abs(s1-s2);
    }
  }
  cout << ABS << endl;
}