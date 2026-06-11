#include <bits/stdc++.h>
using namespace std;
 
int main(){
	vector<int> s(9);
  	for(int i=0;i<9;i++){
    	
         cin >> s.at(i); 
        
    }
  	int n;
  	cin >> n;
  	vector<int> m(n);
  	for(int i=0;i<n;i++){
      cin >> m.at(i);
      for(int j=0;j<9;j++){
      	if(m.at(i) == s.at(j)) s.at(j) = 0;
      }
    }
  	bool e = false;
  	for(int i=0;i<3;i++){
    	if(s.at(i) == 0 && s.at(i+3) == 0 && s.at(i+6) == 0){
             	e = true;
              	break;
        }
    }
       if(s.at(0) == 0 && s.at(1) == 0 && s.at(2) == 0){
             	e = true;
        }
  if(s.at(3) == 0 && s.at(4) == 0 && s.at(5) == 0){
             	e = true;
        }
  if(s.at(6) == 0 && s.at(7) == 0 && s.at(8) == 0){
             	e = true;
        }
  if(s.at(0) == 0 && s.at(4) == 0 && s.at(8) == 0){
             	e = true;
        }
     if(s.at(2) == 0 && s.at(4) == 0 && s.at(6) == 0){
             	e = true;
        }
  if(e == true) cout << "Yes" << endl;
  else cout << "No" << endl;
}