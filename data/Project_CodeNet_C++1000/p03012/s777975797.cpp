#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define ALL(obj) (obj).begin(), (obj).end()

//なんか全然違うの作ってたけどせっかくなので残そう
int main() {
	int n;
  	cin>>n;
    int sum=0;
  	int kotae=0;
  	vector<int> w(n);
  
  	rep(i,n){
      cin>>w[i];
      sum +=w[i];
    }




  int dokomade=w[0];	
  int kotaekamo;
  int hantei=sum/2;
  

  
  for(int j=1;j<n;j++){
    	dokomade+=w[j];
      if(dokomade>=hantei){
        kotaekamo+=(dokomade-w[j]);
          break;
      }
    }
  int kotaekana=dokomade;
  int kotamo=(kotaekamo-hantei)*(kotaekamo-hantei);
  int kotaka=(kotaekana-hantei)*(kotaekana-hantei);
  
  if(kotaka<=kotamo){
  	kotae=kotaekana;
  }
  
  else{
  	kotae=kotaekamo;
  }
  
  //あとは答えを出す
  
  kotae-=sum-kotae;
  //絶対値が欲しいのでマイナスだったら-1かけてプラスにする
  if(kotae<0)kotae*=-1;
  

  cout<<kotae<<endl;
}