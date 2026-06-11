#include<bits/stdc++.h>
using namespace std;
int main(){
  char s;
  cin >> s;
  for(char i='a';i<='z';i++){
    if(i==s){
      i++;
      cout << i << endl;
    }
  }
}
