#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string a;
    cin>>a;
    char k[4];
    for(int i = 0;i<a.length();i++){
      k[i] = a[i];
    }
    sort(k,k+4);
    if(k[0] == k[1] && k[2] == k[3] && k[0]!=k[3]) cout<<"Yes";
    else cout<<"No";
    return 0;
}