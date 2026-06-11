#include <iostream>
#include <string>
using namespace std;

int main(void){
    long long a,v,b,w,t;
    cin >> a >> v >> b >> w >> t;
    
    long long diff = abs(b-a), speed = (v-w);
    
    if(diff <= speed*t) cout << "YES" << endl;
    else cout << "NO" << endl;
 
}
