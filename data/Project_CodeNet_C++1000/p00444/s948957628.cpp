#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cctype>
#define rep(i,a,b) for(int i=(a);i<b;i++)
#define INF 1000000000
#define MAX_N 105
using namespace std;
bool debug=false;

int main(){
  int n;
  int coin[6]={500,100,50,10,5,1};
  while(cin>>n){
    if(n==0)break;
    n=1000-n;
    int cnt=0;
    for(int i=0;i<6;){
      if(n>=coin[i]){
	n-=coin[i];
	cnt++;
	//cout<<coin[i]<<endl;
      }else{
	i++;
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}