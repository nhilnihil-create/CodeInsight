#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b>> c;
    cout<< min(min(a+b,b+c), min(a+b,a+c));
    
    return 0 ;
}