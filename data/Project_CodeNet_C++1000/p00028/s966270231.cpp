#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(int argc, char *argv[])
{
  int x;
  vector<int> freq;
  int X[120] ={0};
  while(cin >>x){
    freq.push_back(x);
}
    int maxf = 0;
  for(int i = 0;i < freq.size();i++){
    X[freq[i]]++;
      maxf = max(maxf,X[freq[i]]);
    }
  for(int j = 0;j < 100;j++){
    if(X[j] == maxf){
      cout << j << endl;
    }
  }
  
  return 0;
}