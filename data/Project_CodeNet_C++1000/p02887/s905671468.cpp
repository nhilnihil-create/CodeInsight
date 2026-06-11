#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  long long int sum = 1;
  cin>>N;
  char arr[N];
  for(int i = 0;i < N;i++){
    cin>>arr[i];
  }
  char c = arr[0];
  for(int i = 1;i < N;i++){
    if(arr[i] == c){

    }else{
      sum += 1;
      c = arr[i];
    }
  }
  cout<<sum<<'\n';
}