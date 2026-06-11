#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  int a[n+1]={false};
  for(int i=0;i<k;i++){
    int s;
    cin >> s;
    for(int j=0;j<s;j++){
      int A;
      cin >> A;
      a[A]=true;
    }
  }
  int count=0;
  for(int i=1;i<=n;i++){
    if(a[i]==false)count++;
  }
  cout << count << endl;
}
    
