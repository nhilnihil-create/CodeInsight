#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void yes(){ cout << "yes" << endl; }
void Yes(){ cout << "Yes" << endl; }
void YES(){ cout << "YES" << endl; }
void no(){ cout << "no" << endl; }
void No(){ cout << "No" << endl; }
void NO(){ cout << "NO" << endl; }
#define rep(i, n)for(int i=0; i<n; i++)

long long INF = 1000000007;

int main(){
  int N, M;  
  cin >> N >> M;
  int s[M], c[M];
  rep(i, M)
    cin >> s[i] >> c[i];
  //

  int start, end;
  if(N==1){
    start = 0;
    end = 9;
  }
  else if(N == 2){
    start = 10;
    end = 99;
  }
  else{
    start = 100;
    end = 999;
  }
  
  for(int n=start; n<=end; n++){
    bool flag = true;
    int tmp;
    rep(i, M){
      tmp = n;
      rep(j, N-s[i])
	tmp /= 10;
      flag = flag*(tmp%10==c[i]);
    }
    if(flag){
      cout<< n <<endl;
      return 0;
    }
  }
    


  
  cout << -1 << endl;

  return 0;
}
