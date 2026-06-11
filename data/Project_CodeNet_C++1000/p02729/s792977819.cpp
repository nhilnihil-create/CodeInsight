#include <vector>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a;
    int l, i = 0;
    while (cin >> l) {
        a.push_back(l);
        i++;
    }
    int b = (a[0]*(a[0]-1)+a[1]*(a[1]-1))/2 ;
    cout << b << endl;
}