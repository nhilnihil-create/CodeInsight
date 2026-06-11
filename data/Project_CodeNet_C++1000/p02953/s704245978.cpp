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
  ll H[N];
  for(int i=0;i<N;i++){
    cin >> H[i];
  }
  bool t = true;
  for(int j=N-1;j>0;j--){
    if(H[j]<H[j-1]){
      --H[j-1];
      if(H[j]!=H[j-1]){
	t = false;
	break;
      }
    }
  }
  if(t) cout << "Yes" << endl;
  else cout << "No" << endl;
}
