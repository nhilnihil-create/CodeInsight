#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long int n,a,b;
    cin >> n >> a >> b;
    long long int x,y;
    x = n/(a+b);
    y = n%(a+b);
    cout << a*x+std::min(y,a) << endl;
}

