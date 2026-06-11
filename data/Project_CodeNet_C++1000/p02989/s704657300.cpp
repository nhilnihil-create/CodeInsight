#include<bits/stdc++.h> 
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  int N;
  cin>>N;
  vector<int> v;
  int a = 0;
  int b = 0;
  int num = 0;
  for(int i = 0;i < N;i++){
    int c;
    cin>>c;
    v.push_back(c);
    //cout<<"ARR"<<arr[N]<<'\n';
  }
  sort(v.begin(),v.end());
  // for(int i = 0;i < N;i++){
  //   num += 1;
  //   if(num * 2 == N){
  //     a = arr[i];
  //     cout<<"A"<<arr[i]<<'\n';
  //     b = arr[i + 1];
  //     cout<<"B"<<arr[i]<<'\n';
  //   }

    // if((i + 1) * 2 == N){
    //   a = arr[i];
    //   b = arr[i + 1];
    //   break;       
    // } 
//}
  cout<<v[v.size() / 2] - v[v.size() / 2 - 1]<<'\n';
}