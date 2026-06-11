#include <bits/stdc++.h>
using namespace std;

int main() {
 vector<vector<int>> card(3, vector<int>(3));
 
 for(int i = 0; i < 3; i++){
	 cin >> card.at(i).at(0); 
     cin >> card.at(i).at(1);
     cin >> card.at(i).at(2);
 }
 int times; cin >> times;
 
 vector<vector<int>> hits(3, vector<int>(3,0));
 for(int i = 0; i < times; i++) {
    int current; cin >> current;
	for(int j = 0; j < 3; j++)  {
      for(int k = 0; k < 3; k++) {
       if(card.at(j).at(k) ==  current) {
        hits.at(j).at(k)++; 
       }
      }
    }
 }
  for(int j = 0; j < 3; j++)  {
    int check = 0;
      for(int k = 0; k < 3; k++) {
        check += hits.at(j).at(k); 
      }
    if(check == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  for(int j = 0; j < 3; j++)  {
    int check = 0;
      for(int k = 0; k < 3; k++) {
        check += hits.at(k).at(j); 
      }
    if(check == 3) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  if(hits.at(1).at(1) == 1) {
   if(hits.at(0).at(0) == 1 && hits.at(2).at(2) == 1 ) {
      cout << "Yes" << endl;
      return 0;
   } else if(hits.at(0).at(2) == 1 && hits.at(2).at(0) == 1 ) {
      cout << "Yes" << endl;
      return 0;
   }
  }
  
  cout << "No" << endl;
  
 return 0; 
}