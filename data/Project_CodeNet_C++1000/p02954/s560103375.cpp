#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int sn,count=1,half,j;
  sn = s.size();
  vector<int>vec(sn);
  
  for(int i=0;i<sn-1;i++){
    if(s.at(i)=='R'&&s.at(i+1)=='L'&&i==sn-2){
      half = count/2;
      count = count - half;
      vec.at(i+1)+=half;
      vec.at(i)+=count;
      j=i;
      count = 1;
      vec.at(i+1)++;
    }
    else if(s.at(i)=='R'&&s.at(i+1)=='L'){
      half = count/2;
      count = count - half;
      vec.at(i+1)+=half;
      vec.at(i)+=count;
      j=i;
      count = 1;
    }
    else if(i==sn-2){
      count++;
      half = count/2;
      count = count - half;
      vec.at(j+1)+=count;
      vec.at(j)+=half;
      count = 1;
    }
    else if(s.at(i)==s.at(i+1)){
      count++;
    }
    else if(s.at(i)=='L'&&s.at(i+1)=='R'){
      half = count/2;
      count = count - half;
      vec.at(j+1)+=count;
      vec.at(j)+=half;
      count = 1;
    }
    
  }
  
  for(int i=0;i<sn;i++){
    cout << vec.at(i) << " ";
  }
  cout << endl;
  
}