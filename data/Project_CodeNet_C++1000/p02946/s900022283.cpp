#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
 
int main() {
    int a,b;cin>>a>>b;
    int hasi = b-(a-1);
    int migi = b+(a-1);
    for(int i = hasi;i<=migi;i++){
      if(i<1000001&&i>-1000001) cout<<i<<" ";
    }
    return 0;
}