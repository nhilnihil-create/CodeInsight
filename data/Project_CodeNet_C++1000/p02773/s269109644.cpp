#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  map<string,int> A;
  for(int i=0;i<N;i++){
    string S;
    cin >> S;
    A[S]++;
  }
  int maxcount=0;
  for(auto it=A.begin();it!=A.end();it++){
    maxcount=max(maxcount,(*it).second);
  }
  for(auto it=A.begin();it!=A.end();it++){
    if(maxcount==(*it).second){
      cout << (*it).first << endl;
    }
  }
}