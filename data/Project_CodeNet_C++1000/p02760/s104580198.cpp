#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>> a(3, vector<int>(3));
    for(int i=0; i<3; ++i){for(int j=0; j<3; ++j){cin >>a[i][j];}}
    int n; cin >> n ;
    vector<int> b(n); 
    for(int j=0; j<n; ++j){cin >> b[j];}

    vector<int> c(9, 0);
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
          	for(int k=0; k<n; ++k){if(a[i][j]==b[k]){c[i*3+j]=1;}}
          	
        }
    }
  
  	

    if(c[0]==1 && c[1]==1 && c[2]==1){cout << "Yes" << endl; return 0;}
    if(c[0]==1 && c[3]==1 && c[6]==1){cout << "Yes" << endl; return 0;}
    if(c[2]==1 && c[5]==1 && c[8]==1){cout << "Yes" << endl; return 0;}
    if(c[6]==1 && c[7]==1 && c[8]==1){cout << "Yes" << endl; return 0;}
    if(c[3]==1 && c[4]==1 && c[5]==1){cout << "Yes" << endl; return 0;}
    if(c[1]==1 && c[4]==1 && c[7]==1){cout << "Yes" << endl; return 0;}
    if(c[0]==1 && c[4]==1 && c[8]==1){cout << "Yes" << endl; return 0;}
    if(c[2]==1 && c[4]==1 && c[6]==1){cout << "Yes" << endl; return 0;}
    
    cout << "No" << endl;

    return 0;
}