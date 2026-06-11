#include<iostream>
#include<string>
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

string str;
vector<int> v(105,0);

int main()
{
  int i=0;
  int m=0;
  int n;
  while(scanf("%d",&n)!=EOF){
    v[n]++;
    i++;
  
  }
  int num=i;

  rep(i,num)
    m=max(m,v[i]);
  
  rep(i,num)
    if(v[i]==m)
      cout<<i<<endl;

}