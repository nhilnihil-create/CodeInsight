#include<iostream>
#define N 300000
using namespace std;


bool p[N];
int num[N];

int main(){

  for(int i=0;i<N;i++)p[i] = true;
  p[0] = p[1] = false;

  for(int i=2;i*i<N;i++){
    if(p[i]){
      for(int j=2*i;j<N;j+=i)p[j] = false;
    }
  }

  int sum = 0;
  for(int i=0;i<N;i++){
    if(p[i])sum++;
    num[i] = sum;
  }

  int n;
  while(cin >> n ,n)cout << num[2*n] - num[n] << endl;
  
}