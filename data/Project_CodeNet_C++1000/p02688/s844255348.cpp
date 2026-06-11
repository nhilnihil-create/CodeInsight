#include <iostream>

using namespace std;

int main(){
  int N,K,x,y,count=0;
  cin >> N >> K;
  int Arr[N];
  for(int d=0;d<N;d++){
    Arr[d]=0;
  }
  for(int a=0;a<K;a++){
    cin >> x;
    for(int b=0;b<x;b++){
      cin >> y;
      Arr[y-1]++;
    }
  }
  for(int c=0;c<N;c++){
    if(Arr[c]==0){
      count++;
    }
  }
  cout << count;
}
