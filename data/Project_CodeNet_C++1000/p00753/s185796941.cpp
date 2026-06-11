#include <bits/stdc++.h>
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define ll long long
#define ull unsigned long long
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

using namespace std;

int main(){

  int n;
  int max_two_n = 123456*2;
  vector<int> prime;
  int j;
  prime.push_back(2);
  for(int i=3;i<=max_two_n;i+=2){
    for(j=0;j<prime.size();j++){
      if(i%prime[j]==0)break;
    }
    if(j==prime.size())prime.push_back(i);
  }
	
  
  while(cin>>n){
    if(!n)break;
    int i=0;
    int ct=0;
    while(true){
      if(prime[i]>2*n)break;
      else if(prime[i]>n)ct++;
      i++;
    }
    cout << ct << endl;
  }     
  return 0;
}