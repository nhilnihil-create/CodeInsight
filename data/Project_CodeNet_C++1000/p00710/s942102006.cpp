#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n,r,p,c;
  while(1){
    cin >> n >> r;
    if (n==0) return 0;
    vector<int> ca(n,0);
    for(int i=0;i<n;i++){
      ca[i]=n-i;
    }
    for(int i=0;i<r;i++){
      cin>>p>>c;
      vector<int>sw(c,0);
      for(int j=0;j<c;j++){
        sw[j]=ca[p-1];
        ca.erase(ca.begin()+p-1);
      }
      for(int j=c-1;j>=0;j--){
        ca.insert(ca.begin(),sw[j]);
      }
    }
    cout << ca[0]<<endl;
  }
}