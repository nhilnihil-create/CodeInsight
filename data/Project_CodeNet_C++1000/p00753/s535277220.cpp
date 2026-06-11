#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (int)(n);++i)
#define pb push_back
#define mp make_pair
#define SZ(a) ((int)(a.size()))
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> PI;

const int MAX_N=123456*3;
bool npr[123456*4];
int sum[123456*4];
int main(int argc, char *argv[])
{
  npr[0] = 1;
  npr[1] = 1;
  for(int i = 2; i < MAX_N;++i){
    if(npr[i]) continue;
    for(int j = 2*i;j<MAX_N; j+=i){
      npr[j] = 1;
    }
  }

  for(int i = 0; i < MAX_N; ++i)
    sum[i+1] = sum[i] + 1-npr[i];
  
  int n;
  while(cin >> n,n){
    cout << sum[n*2+1]-sum[n+1] << endl;
  }
  return 0;
}