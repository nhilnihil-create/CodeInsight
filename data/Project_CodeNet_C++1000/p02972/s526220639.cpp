#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  int a[N];
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  int b[N];
  int all=0;
  memset(b,0,sizeof(b));
  for(int i=N;i>0;i--){
    int sum=0;
    int j=i;
    while (j<=N){
      sum+=b[j-1];
      j += i;
    }
    /*for(int j=i;j<N+1;j++){
      if(j%N==0) sum+=b[j-1];
      }*/
    if(sum%2!=a[i-1]) {
      b[i-1]=1;
    }
    all += b[i-1];
  }
  cout << all << endl;
  for (int i=0;i<N;i++){
    if(b[i]==1) cout << i+1 << " ";
  }
}
