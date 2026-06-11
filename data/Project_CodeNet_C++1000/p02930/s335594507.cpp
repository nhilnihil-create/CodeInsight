// complete graph with N nodes
// each edge has an positive integer as weight
// for any node i , if we travell by edges with same node , when we return to i
// each edge in our tour has been used even number time
// assign weights to each edge st the maximal weight is minimzed

#include <iostream>
using namespace std;

int N;



int main(){
  cin >> N;
  for(int i = 1; i <= N - 1; ++i){
    for(int j = i + 1; j <= N; ++j){
      int k = i ^ j;
      for(int x = 0; x < 30; ++x){
        if((1 << x) & k){
          cout << x + 1 << " ";
          break;
        }
      }
    }
    cout << endl;
  }
  return 0;
}
