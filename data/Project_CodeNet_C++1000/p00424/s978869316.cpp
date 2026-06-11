#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n,m;
  char c;
  vector<char> transB,transA;
  vector<char> input; 
  while(cin >> n){
    if(n == 0)
      return 0;

    transB.clear(); transA.clear(); input.clear();
    for(int i =0;i<n;i++){
      cin >> c;
      transB.push_back(c); 
      cin >> c;
      transA.push_back(c);
 }
      
    cin >> m;
   for(int i=0;i<m;i++){
     cin >> c;
     input.push_back(c);
  }
  for(int i=0;i<m;i++){
    for(int k =0;k < n;k++){ 
      if(input[i] == transB[k]){
	input[i] = transA[k];  break;
    }
    }
  }

  for(int i = 0;i<m;i++){
    cout << input[i];
    }
    cout << endl;
  }
}
  
  