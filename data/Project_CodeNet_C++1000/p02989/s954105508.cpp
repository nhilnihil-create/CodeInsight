#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  int d=N/2-1;
  int a[N];
  vector<int> s;
  for(int i=0;i<N;i++){
    cin>>a[i];
      s.push_back(a[i]);
  }
    sort(s.begin(),s.end());
    cout<<s[d+1]-s[d]<<endl;
}