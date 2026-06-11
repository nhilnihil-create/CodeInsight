#include <iostream>

using namespace std;

int main()
{
  int N,M;
  
   while(cin >> N >> M,N + M){
    int h[1600],w[1600];
    int counth[1500001] = {0};
    int countw[1500001] = {0};
    
    for(int i = 0;i < N;i++){
      cin >> h[i];
    }  

    for(int i = 0;i < M;i++){
      cin >> w[i];
    }

  for(int i = 0;i < N;i++){
    int sum;
    for(int j = i;j < N;j++){
      if(i == j){
	sum = h[i];
      } else {
	sum += h[j];
      }  
      counth[sum]++;
    }
  }

  for(int i = 0;i < M;i++){
    int sum;
    for(int j = i;j < M;j++){
      if(i == j){
	sum = w[i];
      } else {
	sum += w[j];
      }  
      countw[sum]++;
    }
  }

  int sum = 0;

  for(int i = 0;i < 1500001;i++){
    sum += counth[i] * countw[i];
  }

  cout << sum << endl;

  }
}

