#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,num;
  cin>>n>>k;
  vector<int> arr;
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>num;
    arr.push_back(num);
  }
  sort(arr.begin(),arr.end());
  for(int i=0;i<k;i++){
    sum+=arr[i];
  }
  cout<<sum<<endl;
  return 0;
}
