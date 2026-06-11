//MISHON69
//DATE:6/22/2020
#include<bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  stack<char>s;
  int n;
  cin>>n;
  getchar();
  FOR(i,n){
     char temp;
     cin>>temp;
     s.push(temp);
  }
  char temp1=s.top();
  s.pop();
  int sum=1;
  while(!s.empty()){
    char temp2=s.top();
    s.pop();
    if(temp2!=temp1){
       temp1=temp2;
       sum++;
    }
  }
  cout<<sum<<endl;
}