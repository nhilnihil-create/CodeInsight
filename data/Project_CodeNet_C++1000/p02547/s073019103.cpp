#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int renzoku = 0;
    for(int i= 0;i<n;i++){
     int d1,d2;cin>>d1>>d2;
     if(d1 == d2){
     	renzoku+=1;
     }
     else{
       renzoku = 0;
     }
     if(renzoku >= 3){
      cout<<"Yes";
      return 0;
     }
    }
    cout<<"No";
    return 0;
}