#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int curr = 1;
  int a,b;
  cin>>a>>b;
  int need = 0;
  while(curr<b){
    curr+=(a-1);
	need++;
  }
  cout<<need;
}