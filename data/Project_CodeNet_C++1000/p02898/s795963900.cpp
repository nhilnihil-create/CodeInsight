#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n,k ;
    cin >>n>>k;
    int kazu = 0;
    for(int i = 0;i<n;i++){
      int t; cin >> t;
      if(t >= k) kazu++;
    }
    cout<<kazu;
    return 0;
}