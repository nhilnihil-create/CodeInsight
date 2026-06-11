#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#define ll long long 
#define d double
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h,a;
  cin>>h>>a;
  int count=0;
  while(h>0){
  	h-=a;
  	count++; 	
  }
  cout<<count<<endl;
  
  return 0;
}