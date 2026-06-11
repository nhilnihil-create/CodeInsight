#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    n %= 1000;
    cout << ((n)?1000-n:n) << endl;
}