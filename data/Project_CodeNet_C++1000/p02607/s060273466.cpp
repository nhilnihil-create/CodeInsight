#include <iostream>

using namespace std;

int main(){
  
  int n;
  cin >> n;
  int y, count=0;
  
  for(int x=0;x<n;x++){
    cin >> y;
    if(x%2==0&&y%2==1){
      count++;
    }
  }
  
  cout << count;
}