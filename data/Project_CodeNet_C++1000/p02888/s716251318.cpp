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
  int L[N];
  for(int i=0;i<N;i++){
    cin >> L[i];
  }
  sort(L,L+N);
  ll num=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      for(int n=j+1;n<N;n++){
	if(L[i]+L[j]<=L[n]) break;
	else num++;
      }
    }
  }
  cout << num << endl;
}
