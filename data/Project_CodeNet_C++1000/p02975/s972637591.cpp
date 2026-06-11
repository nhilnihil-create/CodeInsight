#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>A(N);
  bool B=true;
  map<int,int>C;
  for(int i=0;i<N;i++){
    cin>>A[i];
    if(A[i]!=0)B=false;
    C[A[i]]++;
  }
  if(B){puts("Yes");return 0;}
  if(N%3!=0){puts("No");return 0;}
  int k=0;
  vector<pair<int,int>>E(3);
  for(pair<int,int>D:C){
    k++;if(k>=4){puts("No");return 0;}
    E[k-1].first=D.first;E[k-1].second=D.second;
  }
  if(k==2){if(E[0].first==0&&E[0].second*2==E[1].second){puts("Yes");return 0;}}
  else if(E[0].second==E[1].second&&E[1].second==E[2].second&&((E[0].first^E[1].first)^E[2].first)==0){puts("Yes");return 0;}
  puts("No");
}