#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,d; cin >> n >> d;
  vector<vector<int>> a(n,vector<int>(d));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < d; j++){
      cin >> a.at(i).at(j);
    }
  }
  int cnt = 0;
  double distance = 0;
  for(int i = 0;i < n - 1; i++){
    for(int j = i +1; j < n; j++){
      for(int k = 0; k < d; k++){
        //printf("%d %d\n",a.at(i).at(k),a.at(j).at(k));
      	distance += (a.at(i).at(k) - a.at(j).at(k)) * (a.at(i).at(k) - a.at(j).at(k));
      }
    distance = sqrt(distance);
   // cout << distance << endl;;
    if(ceil(distance) == floor(distance)) cnt++;
    distance = 0;
    }

  }
  
  cout << cnt;      
}