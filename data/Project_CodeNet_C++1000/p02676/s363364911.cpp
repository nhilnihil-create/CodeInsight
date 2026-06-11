#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    int k;
    cin >> k;
    string s, ans;
    cin >> s;
 
    int t = s.size();
    if(t <= k) {
        cout << s << endl;
    }else{
      for (int j = 0; j < k; j++){
          cout << s.at(j);
      }
      cout << "..." << endl;
    }

}