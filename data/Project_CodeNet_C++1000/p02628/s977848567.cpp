#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  int K;
  vector <int> gyumolcs;
  cin >> N;
  cin >> K;
  int seged;
  for(int i=0;i<N;i++){
    cin >> seged;
    gyumolcs.push_back(seged);
  }
  int oszzeadas=0;
  for(int j=0;j<K;j++){
    int min=gyumolcs[0];
    int mini=0;
    for(int i=1;i<gyumolcs.size();i++){
      if(gyumolcs[i]<min){
        min=gyumolcs[i];
        mini=i;
      }
      }
      oszzeadas+=min;
      gyumolcs[mini]+=1000;
    
  }
  cout << oszzeadas;
	return 0;
}
