#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main(){
    int x;
    cin >> x;
    cout << (1000 * (x / 500)) + (5 * ((x%500) / 5)) << endl;
}