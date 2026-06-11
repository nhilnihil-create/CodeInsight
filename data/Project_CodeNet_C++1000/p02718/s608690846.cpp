#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  int M;
  int num = 0;
  double sum = 0;
  cin>>N;
  cin>>M;
  int arr[N];
  for(int i = 0;i < N;i++){
    cin>>arr[i];
    sum += arr[i];
  }
  sort(arr,arr + (N),greater<int>());
  for(int i = 0;i < M;i++){
    if(arr[i] < (sum / (4*M))){
      cout<<"No"<<'\n';
      num = 1;
      break;
    }
  }
  if(num == 0){
    cout<<"Yes"<<'\n';
  }
}