#include<iostream>
#include<vector>

using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> zorome(n,0);
  int d0,d1;
  for(int i=0;i<n;i++){
    cin >> d0 >> d1;
    if(d0==d1){
      zorome.at(i)=1;
    }
  }
  for(int i=0;i<n-2;i++){
    if(zorome.at(i)*zorome.at(i+1)*zorome.at(i+2)==1){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}