#include <iostream>
#include <cmath>

using namespace std;
int main(){
    long n;
    cin >> n;
    int x;
    for(int i=1; i <= sqrt(n); i++) {
        if(n%i==0) x = i;
    }
    cout << x+(n/x)-2 << endl;
}