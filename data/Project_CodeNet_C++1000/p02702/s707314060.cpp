//解説視聴後
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#define rep(i,n) for(int i=0; i < (n); i++)
#define INF 1001001
using namespace std;
 
int main(){
  string s;
  cin >> s;
  int len = (int)(s.length());
  int mod[len];
  int num[2019];
  mod[len-1]=(int)s[len-1] - '0';
  int tmp=10;
  for(int i=len-2;i>=0; i--){
    mod[i]=(mod[i+1]+tmp*((int)(s[i])-'0'))%2019;
    tmp = (tmp*10)%2019;
  }
  rep(i,2019){
    num[i]=0;
  }
  rep(i,len){
    num[mod[i]]++;
  }
  if(num[0]>0) num[0]++;
  long long result=0;
  rep(i,2019){
    if(num[i]<=1) continue;
    result += num[i]*(num[i]-1);
  }
  result = result /2;
  
  cout << result << endl;
  
  
}