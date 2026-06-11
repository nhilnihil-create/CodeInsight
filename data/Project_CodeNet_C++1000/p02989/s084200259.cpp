#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    int d[n];
    if(n%2==1){
     cout<<0;
     return 0;
    }
    for(int i = 0;i<n;i++) cin >> d[i];
    sort(d,d+n);
    int dm = d[n/2];
    int sm = d[n/2-1];
    if(dm == sm){
     cout<<0;
     return 0;
    }
    else{
      cout<<dm-sm;
    }
    return 0;
}