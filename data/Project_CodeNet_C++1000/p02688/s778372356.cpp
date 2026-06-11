#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >>n>>k;
  int num[n]={0};
  for (int i=0;i<k;i++){
    int a;
    cin >>a;
    for (int j=0;j<a;j++){
      int b=0;
      cin >>b;
      for(int m=0;m<n;m++){
        if(b==m+1) ++num[m];
      }
    }
  }
  int p=0;
  for(int i=0;i<n;i++){
    if(num[i]==0) p++;
  }
  cout << p<<endl;
}