typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int main() {
    ll t1,t2,a1,a2,b1,b2;
    std::cin >> t1>>t2;
    std::cin >> a1>>a2;
    std::cin >> b1>>b2;
    
    if(a1*t1+a2*t2 == b1*t1+b2*t2){
        std::cout << "infinity" << std::endl;
        return 0;
    }
    
    if(a1*t1+a2*t2 < b1*t1+b2*t2){
        swap(a1,b1);
        swap(a2,b2);
    }
    
    if( t1*(b1-a1) < 0 ){
        std::cout << 0 << std::endl;
        return 0;
    }
    ll res = (a1-b1)*t1/((b1-a1)*t1+(b2-a2)*t2);
    
    if(  (a1-b1)*t1%((b1-a1)*t1+(b2-a2)*t2)==0){
        std::cout << res*2 << std::endl;
    }else{
        std::cout << res*2+1 << std::endl;
    }
    
}
