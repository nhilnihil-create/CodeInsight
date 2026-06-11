#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> s(N);
  for(int i=0;i<N;i++){
    cin >> s[i];
  }
  int cnt=1;
  for(int i=0;i<N;i++){
    if(s[i]%2==0){
     if(s[i]%3!=0&&s[i]%5!=0){
       cnt=0;
       break;
     }
    }
  }
  
  if(cnt){
    cout << "APPROVED" <<endl;
  }
  else{
    cout << "DENIED" <<endl;
  }
}
