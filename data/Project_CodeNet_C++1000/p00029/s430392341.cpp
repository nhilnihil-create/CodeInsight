#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
typedef pair<int, int> P;

char str[1005];
char v[1005][33];
int  n[1005];
int main()
{
  int i,j,k=0;
  int maxi=0;

  gets(str);

  rep(i,1000){
    rep(j,33)
    {
      if(str[k]==' '|| str[k]=='\0'){
	v[i][j]='\0';
	k++;
	break;
      }
      v[i][j]=str[k];
      k++;
    }
    if(k>=strlen(str))break;
  }
  int num=i+1;

  rep(i,num)
    {
      n[i]=0;
    }

  rep(i,num){
    if( strlen(v[maxi]) < strlen(v[i]) )
      maxi=i;
    if(n[i])continue;
    for(j=i+1;j<num;j++){
      if(strcmp(v[i],v[j])==0){
	n[i]++;
	n[j]++;
      }
    }
  }
  int mode=0;

  for(i=1;i<num;i++)
    if(n[mode]<n[i])
      mode=i;

  cout<<v[mode]<<" ";
  cout<<v[maxi]<<endl;
}