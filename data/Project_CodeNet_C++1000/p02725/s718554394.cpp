#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> k >> n;
  vector<int>kyo(n);
  int b,no,c;
  cin >> b;
  c=b;
  for(int i=0;i<n-1;i++){
    no=b;
    cin >> b;
    kyo.at(i)=b-no;
  }
  kyo.at(n-1)=k-b+c;
  sort(kyo.begin(),kyo.end(),greater());
  cout << k-kyo.at(0) << endl;
  return 0;
}