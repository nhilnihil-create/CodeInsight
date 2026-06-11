#include <iostream>
#include <vector>

using namespace std;

int main(){
  int i;
  int N;
  cin >> N;
  
  vector <int> a(N);
  for(i=0; i<N; i++){
    cin >> a[i];
  }
  
  int count = 0;
  for(i=0; i<=N/2; i++){
    int ii = 2*i;
    if(a[ii]%2 == 1) count++;
  }
  
  cout << count << endl;
  
  return 0;
}