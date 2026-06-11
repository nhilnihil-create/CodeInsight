#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
  int time[100000];

  int n;
  while(cin>>n,n!=0){
      memset(time,0,sizeof(time));
      for(int i = 0;i<n;i++){
	int h,m,s;
	scanf("%d:%d:%d",&h,&m,&s);
	time[h * (60*60) + m * 60 + s]++;
	scanf("%d:%d:%d",&h,&m,&s);
	time[h * (60*60) + m * 60 + s]--;
      }
      for(int i = 1;i<=24*60*60;i++){
	time[i] += time[i-1];
      }
      cout<<*max_element(time,time+24*60*60)<<endl;
  }

  return 0;
}