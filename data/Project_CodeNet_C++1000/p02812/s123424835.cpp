#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  char N[n]={};
  int count=0;
  for(int i=0;i<n;i++){
    cin >> N[i];
    if(N[i-2]=='A' && N[i-1]=='B' && N[i]=='C')count++;
  }
  cout << count << endl;
}