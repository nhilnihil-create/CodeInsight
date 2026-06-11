#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k,s;
  cin >> n >> k >> s;
  int a[s]={0};
  vector<int> b(n,k);
  int count=0;
  for(int i=0;i<s;i++){
    cin >> a[i];
    b[a[i]-1]++;
    count++;
  }
  for(int i=0;i<n;i++){
    b[i]-=count;
    if(b[i]>0)cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}

  