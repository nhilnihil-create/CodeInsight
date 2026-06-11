#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> a(M), broken(N,0);
  for(int i=0; i<M; i++){
    cin >> a.at(i);
    broken.at(a.at(i))++;
  }
  vector<int> mtd(N+1,0);
  const int MOD = 1000000007;
  if((N>=2 && broken.at(1)==0) || N==1){
    mtd.at(1) = 1;
  }
  if((N>=3 && broken.at(2)==0) || N==2){
    mtd.at(2) = mtd.at(1)+1;
  }
  for(int i=3; i<N; i++){
    if(broken.at(i)==0){
      mtd.at(i) = mtd.at(i-2)*(1-broken.at(i-2))+
        			mtd.at(i-1)*(1-broken.at(i-1));
    }
    if(mtd.at(i)>=MOD){
      mtd.at(i) %= MOD;
    }
    if(i==N-1){
      mtd.at(N) = (mtd.at(N-2)*(1-broken.at(N-2))+
        		mtd.at(N-1)*(1-broken.at(N-1))) % MOD;
    }
  }
  cout << mtd.at(N);
  return 0;
}