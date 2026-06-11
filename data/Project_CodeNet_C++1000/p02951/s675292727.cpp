#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    int d = a-b;
    int k = c-d;
    if(k<=0) k= 0;
    cout<<k;
    return 0;
}