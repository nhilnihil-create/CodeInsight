#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
	long x,k,d;
    cin>>x>>k>>d;
  	long kk = abs(x)+d;//距離
    long nn = 0;//何回でアウトしたか
    
    nn = abs(x)/d;
    if(nn > k) nn = k;
    kk = abs(x)-nn*d;
    
  
    long nokori = k-nn;
    if(nokori%2 == 0) cout<<kk;
    else cout<<abs(kk -d);
    return 0;
}