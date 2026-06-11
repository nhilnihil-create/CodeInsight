#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
typedef pair<int, int> pii;

int main()
{
  int m,nmin,nmax;
  int i,j;

  while(true){
    cin>>m>>nmin>>nmax;
    if(m==0 && nmin==0 && nmax==0)break;
    int score[200]={};
    rep(i,m)
      cin>>score[i];
    rep(i,m-1)
      score[i]-=score[i+1];

    pii p[200]={};
    int n=0;
    for(i=nmin-1;i<=nmax-1;i++){
      p[n].first=score[i];
      p[n].second=i+1;
      n++;
    }
    int num=nmax-nmin+1;
    sort(p,p+num);

    cout<<p[num-1].second<<endl;

  }

}