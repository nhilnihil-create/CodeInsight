#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <cmath> 

using namespace std;
 
int main() {
    int a,b;
    cin>>a>>b;
  
    int c;
    if(a > b)  c = a;
    else c = b;
    for(int i = 1;i<c;i++){
      if(abs(a-i) == abs(b-i)){
        cout<<i;
        return 0;
      }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}