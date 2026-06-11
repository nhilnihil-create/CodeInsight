#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int a,b;
    cin >>a>>b;
    int k = a-(b*2);
    if(k <0) k = 0;
    cout<<k;
    return 0;
}