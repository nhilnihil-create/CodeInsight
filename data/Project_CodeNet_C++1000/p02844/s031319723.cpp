#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>data(N);
  for(int i=0;i<N;i++){
    char s;
    cin >> s;
    data.at(i)=int(s)-int('0');
  }
  vector<vector<int>>kazugoto(10,vector<int>(2));
  for(int i=0;i<10;i++){
    kazugoto.at(i).at(0)=-1;
  }
  for(int i=0;i<N;i++){
    kazugoto.at(data.at(i)).at(1)=i;
    if(kazugoto.at(data.at(i)).at(0)==-1) kazugoto.at(data.at(i)).at(0)=i;
  }
  int count=0;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(kazugoto.at(i).at(0)==-1||kazugoto.at(j).at(0)==-1) continue;
      if(kazugoto.at(i).at(0)>=kazugoto.at(j).at(1)-1) continue;
      set<int>result;
      for(int k=kazugoto.at(i).at(0)+1;k<kazugoto.at(j).at(1);k++){
        result.insert(data.at(k));
      }
      count+=result.size();
    }
  }
  cout << count << endl; 
}