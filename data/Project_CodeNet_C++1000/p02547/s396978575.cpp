#include<iostream>
using namespace std;

int main(){
 int n;		cin >> n;
  int a[n], b[n];
  int same_cnt=0;
  
  for(int i=0; i<n; i++){
    cin >> a[i] >> b[i];
  }
  
  for(int i=0; i<n; i++){
   if(a[i] == b[i]){
    same_cnt++; 
   }else{
     same_cnt = 0;
   }
    if(same_cnt >= 3){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}

