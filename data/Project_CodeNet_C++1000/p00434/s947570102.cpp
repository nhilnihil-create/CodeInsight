#include<iostream>

using namespace std;

int sd[31];
int main(){
  int a;
  
  for(int i = 0; i < 28; i++){
    cin >> a;
    sd[a] = 1;
  }
  for(int i = 1; i <= 30; i++){
    if(sd[i] == 0) cout << i << endl;
  }
}