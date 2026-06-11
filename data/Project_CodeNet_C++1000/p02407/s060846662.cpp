#include <iostream>
using namespace std;

int main(){
 int n;
  cin >> n;
  int test[n]={};
  
  for(int i=0;i<n;i++){
    
    cin >> test[i];  
  }
  
  for(int i=n-1;i>=1;i--){
    
    cout << test[i] << ' ' ;
    
  } 
  cout << test[0] << endl;
}
