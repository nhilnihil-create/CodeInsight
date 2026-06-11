#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string a;cin>>a;
    for(int i = 0;i<a.size();i++){
      if(i%2 == 0){
         if(a[i] == 'L'){
           cout<<"No";
           return 0;
         }
      }
      if(i%2 == 1){
         if(a[i] == 'R'){
           cout<<"No";
           return 0;
         }
      }
    
    }
    cout << "Yes";
    return 0;
}