#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int e = n * (n-1) / 2;
    int o = m * (m-1) / 2;

    cout << e + o << endl;
}
