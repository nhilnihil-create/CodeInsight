#include<iostream>
#include<cmath>
#include<vector>
#define N 250000

using namespace std;

int main(){
  int i, j, n, isFound;
  vector<int> data;

  data.push_back(2);
  data.push_back(3);
  for(i=5; i<=N; i+=2){
    for(j=1, isFound=0; data[j]<=sqrt(i); ++j){
      if(i%data[j] == 0){
	isFound = 1;
	break;
      }
    }
    if(isFound == 0) data.push_back(i);
  }

  while(1){
    cin >> n;
    if(n == 0) break;

    for(i=0; i<data.size(); ++i){
      if(data[i] > n) break;
    }
    for(j=i+1; j<data.size(); ++j){
      if(data[j] >= 2*n) break;
    }

    cout << j-i << endl;
  }

  return 0;
}