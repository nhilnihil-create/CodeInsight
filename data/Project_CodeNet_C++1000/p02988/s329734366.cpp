#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int p[n];
    int ok= 0;
    for(int i = 0;i<n;i++) cin >> p[i];
    for(int i = 1;i<=n-2;i++){
      if(p[i-1] < p[i] && p[i]< p[i+1]) ok++;
      if(p[i-1] > p[i] && p[i]> p[i+1])ok++;
    }
    cout<<ok;
    return 0;
}