#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  int a1[N],a2[N],combo=0,f=0;
  for(int a=0;a<N;a++){
    cin >> a1[a] >> a2[a];
    if(a1[a]==a2[a]){
      combo++;
    }else{
      combo=0;
    }
    if(combo>=3){
      f++;
    }
  }
  if(f>0){
    cout << "Yes";
  }else{
    cout << "No";
  }
}