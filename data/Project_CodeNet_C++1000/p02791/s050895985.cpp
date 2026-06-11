#include<bits/stdc++.h>
using namespace std;

int main(){
 int N;
  cin >>N;
  vector<int> a(N);
  for(int i=0;i<N;i++){
    cin >> a[i];
  }
  
  int b=a[0],ans=0;
  for(int i=0;i<N;i++){
    if(a[i]<=b){
      ans++;
    }
    b=min(b,a[i]);
  }
  cout << ans <<endl;
}