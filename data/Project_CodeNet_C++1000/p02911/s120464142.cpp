#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k,q;
  cin>>n>>k>>q;
  vector<int> a(n);
  vector<long long> challenger(n,k);
  for(int i=0;i<q;i++){
    int a;
    cin>>a;
    a--;
    challenger[a]++;
  }
  for(int i=0;i<n;i++)challenger[i]-=q;
  for(int i=0;i<n;i++){
    if(challenger[i]>0){
      cout<<"Yes"<<endl;
    }else{
      cout<<"No"<<endl;
    }
  }
  return 0;
}