#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> A(N);
  for(int i=1;i<N;i++){
    int a;
    cin>>a;
    A[a-1]++;
  }
  for(int &i:A)
    cout<<i<<endl;
}