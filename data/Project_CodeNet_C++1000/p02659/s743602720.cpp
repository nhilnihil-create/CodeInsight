#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
int mod = (int) 1e9 + 7;

int main(){
    
    long a;
    double b;
    cin >> a >> b;
    
    int c = b * 100 + 0.001;
    
    long d = a * c / 100;
    
    cout << d << "\n";
    
    return 0;
}

