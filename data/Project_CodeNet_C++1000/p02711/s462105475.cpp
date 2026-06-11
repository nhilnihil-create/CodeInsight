#include <bits/stdc++.h>
using namespace std;

int main()
{
    string N;
    cin >> N;
    for (int i = 0; i < N.size();i++){
        if(N.at(i)=='7'){
            cout << "Yes" << endl;
            break;
        }
        else if (N.at(i) != '7'){
          if(i<N.size()-1){
            continue;
          }
          else if(i==N.size()-1){
             cout << "No" << endl;
          }
        }
        
    }
   
}
