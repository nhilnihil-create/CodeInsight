#include <iostream>
using namespace std;
int main(void){
    long a,b,v,w,t;
    cin >> a >> v;
    cin >> b >> w;
    cin >> t; 
    
    
    if(v > w){
          long d = abs(a - b);
          if(d <= t * (v - w)){
                cout << "YES" << endl;
          }else{
                cout << "NO" << endl;
          }
    }else{
          cout << "NO" << endl;
    }
}
