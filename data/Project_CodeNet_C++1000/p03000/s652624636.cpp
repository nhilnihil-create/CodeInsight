#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n,x;
  cin >> n >> x;
  int i,s=0,c=1,l;
  for(i=0;i<n;i++){
    cin >> l;
    s += l;
    if(s>x){
      cout << c << endl;
      return 0;
    }else{
      c++;
    }
  }
  
  cout << c << endl;
}