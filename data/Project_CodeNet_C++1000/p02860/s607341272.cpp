#include <bits/stdc++.h>
using namespace std;
int main() {
    int N ;
    string S ;
    cin >> N;
    cin >> S;
    if (N % 2 != 0){
      cout << "No" << endl;
    }
    else {  
      int n = N / 2;
      string S2 = S;
      string s1 = S.erase(n);
      string s2 = S2.substr(n);
      if (s1 == s2){
          cout<<"Yes"<<endl;
      }
      else {
          cout<<"No"<<endl;
      }
    }
}
