#include <iostream>
#define rep(i, n)for(int i=0; i<n; i++)
using namespace std;

int main(){
    int n, digit=1;
    cin >> n;
    int n1 = n;
    rep(i, 6){
        n /= 10;
        if(n!=0)digit++;
    }

    if(digit==1) cout << n1 << endl;
    else if(digit==2) cout << 9 << endl;
    else if(digit==3) cout << n1-90 << endl;
    else if(digit==4) cout << 909 << endl;
    else if(digit==5) cout << n1-9090 << endl;
    else if(digit==6) cout << 90909 << endl;
    
    return 0;
}
