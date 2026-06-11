#include <iostream>
#include <cmath>
#define rep(i,n) for(int i=0 ; i < n ; i++)
#define N 300000

using namespace std;

int main()
{

  int array[N] = {0};
  rep(i, N){
    array[i] = 1;
  }
  array[0] = 0;
  array[1] = 0;
  
  int end;
  end = (int)sqrt((double)N);
  for(int i = 2 ; i < end ; i++){
    if(array[i] == 1){
      for(int j = i*2 ; j <= N ; j+=i){
	array[j] = 0;
      }
    }
  }
  
  while(true){
    int n;
    cin >> n;
    if(n == 0) break;

   
    int num = 0;
    for(int i = n+1 ; i <= 2 * n ; i++){
      if(array[i] == 1){
	num++;
      }
    }
    cout << num << '\n';
  }

}