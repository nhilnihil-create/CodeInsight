#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    string a,b;
    cin >>a>>b;
    int d;
    for(int i = 0;i<3;i++){
     if(a[i] == b[i]) d++;
    }
    cout<<d;
    return 0;
}