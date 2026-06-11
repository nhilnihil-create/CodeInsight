#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> a(N);
  for (int i = 0; i<N; i++) cin >> a[i];
  int sum = 0;  
  for(int i= 0; i< N; i++)sum += a[i];
  int count=0;
  for(int i=0;i<N;i++){
    if (a[i]*4*M>=sum){
      count++;
    }
  }
  if(count>=M) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}