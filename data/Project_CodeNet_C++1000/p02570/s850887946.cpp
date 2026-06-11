#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    double d,t,s;
    cin>>d>>t>>s;
    if(d/s <= t)cout<<"Yes";
    else cout<<"No";
    return 0;
}