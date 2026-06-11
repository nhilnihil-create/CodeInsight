#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<vector<char>> A(6,vector<char>(6));
  long long H,W,K;
  cin >>H>>W>>K;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>A.at(i).at(j);
    }
  }
  
  vector<vector<char>> copy =A;
  
  long long maincount=0;
  
  for (int tmp = 0; tmp < (1 << (H+W)); tmp++) {
    bitset<12> p (tmp);
    long long count=0;
    A=copy;
     
    for(int a=0;a<H;a++){
      if(p.test(a)){
        A.at(a)=vector<char>(6);
      }
    }
    for(int b=H;b<H+W;b++){
      if(p.test(b)){
        for(int c=0;c<H;c++){
          A.at(c).at(b-H)='0';
        }
      }
    }    
    
    for (int x = 0; x < H; x++) {
      for (int y = 0; y < W; y++) {
        if (A.at(x).at(y) =='#') {
            count++;
          }
       }
    }   
    
    if(count==K){
      maincount++;
    }
  }
  
  
  cout << maincount;
}