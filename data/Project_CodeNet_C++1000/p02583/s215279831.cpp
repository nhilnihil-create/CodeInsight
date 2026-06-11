#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,count=0;
  cin >> a;
  vector<int> mama(a);
  for (int i=0;i<a;i++){
    cin >> mama.at(i);
  }
  sort(mama.begin(),mama.end());
  for (int i=0;i<a;i++){
    for (int j=i+1;j<a;j++){
      if (mama.at(i)==mama.at(j)) continue;
      for (int k=j+1;k<a;k++){
        if (mama.at(j)==mama.at(k)) continue;
        if (mama.at(i)+mama.at(j) > mama.at(k)) count ++;
      }
    }
  }
  
  cout << count << endl;
}