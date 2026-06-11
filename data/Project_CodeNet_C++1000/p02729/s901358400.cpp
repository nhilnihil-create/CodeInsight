#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int ret = n * (n-1) / 2 + m * (m-1) / 2;
    cout << ret << '\n';
}