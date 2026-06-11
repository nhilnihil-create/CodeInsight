#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if(a1+a2+a3 <= 21) cout << "win" << endl;
    else cout << "bust" << endl;
    return 0;
}