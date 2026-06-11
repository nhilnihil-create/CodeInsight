#include<iostream>

using namespace std;

int main(){
  long x = 0, y = 0, num = 0, dis = 0, count = 0;
  
  cin >> num;
  cin >> dis;
  
  for(int i = 0; i < num; i++){
  	cin >> x;
    cin >> y;
    
    if((x * x) + (y * y) <= dis * dis){
      count++;
    }
  }
  cout << count << endl;
}