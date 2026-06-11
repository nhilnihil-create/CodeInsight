#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1,str2;

int m[1000][1000];

int LCS(int i,int j){
  
  
  if(i==-1||j==-1){
    return 0;
  }else if(m[i][j]!=0){
    return m[i][j];
  }else if(str1[i]==str2[j]){
    m[i][j]=LCS(i-1,j-1)+1;
    return m[i][j];
  }else{
    m[i][j]=max(LCS(i-1,j),LCS(i,j-1));
    return m[i][j];
  }
  
}

int main(){
  int N;
  
  cin >> N;
  
  
  for(int i=0;i<N;i++){
    cin >> str1 >> str2;
    for(int j=0;j<1000;j++){
      for(int k=0;k<1000;k++){
        m[j][k]=0;
      }
    }
    cout << LCS(str1.size()-1,str2.size()-1) << endl;
  }
  return 0;
}