#include<iostream>

using namespace std;

#define N 123456*2+1

char prime[N];

void make(){

  for(int i = 0; i < N; i++) prime[i] = '1';
  prime[0] = '0';
  prime[1] = '0';

  for(int i = 2; i*i < N; i++){
    if(prime[i] == '1'){
      for(int j = i*2; j < N; j+=i){
	prime[j] = '0';
      }
    }
  }

}

int main(){

  make();

  int in;

  while(cin >> in){
    if(in == 0) break;

    int sum = 0;

    for(int i = in+1; i <= in*2; i++){
      if(prime[i] == '1') sum++;
    }

    cout << sum << endl;

  }

  return 0;
}