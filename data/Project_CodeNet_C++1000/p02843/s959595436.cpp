#include<bits/stdc++.h>
using namespace std;
int main(){
  int x; cin >> x;
  int kosuu = x/100;
  int hasuu = x % 100;
 // cout << kosuu << " " << hasuu << endl;
  if(hasuu >  5 * kosuu)
    cout << 0;
  else
    cout << 1;
}
        
  
