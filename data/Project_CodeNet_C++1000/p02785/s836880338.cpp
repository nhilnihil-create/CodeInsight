#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  int K;
  int a = 0;
  long long int sum = 0;
  cin>>N;
  cin>>K;
  int arr[N];
  for(int i = 0;i < N;i++){
    cin>>arr[i];
  }
  sort(arr,arr + (N),greater<int>());
  for(int i = 0;i <= N && i < K;i++){
    arr[i] = 0;
    a += 1;
  }
  for(int i = a;i < N;i++){
    sum += arr[i];
    //cout<<"A"<<arr[i]<<'\n';   
  }
  cout<<sum<<'\n';
}