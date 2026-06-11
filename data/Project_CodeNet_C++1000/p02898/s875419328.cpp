#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  int K;
  vector <int> magassag;
  cin >> N;
  cin >> K;
  int seged;
  for(int i=0;i<N;i++){
    cin >> seged;
     magassag.push_back(seged);
  }
  seged=0;
  for(int j=0;j<N;j++){
    if(magassag[j]>=K){
      seged+=1;
    }
  }
  cout << seged;
	return 0;
}
