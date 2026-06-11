#include<bits/stdc++.h>
using namespace std;

int main(){
  int r;
  cin >> r;
  if(r/100==7||(r/10)%10==7||r%10==7){
    cout << "Yes"<<endl;
  }else {
    cout << "No"<<endl;
  }
}
