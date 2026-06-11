#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int n, a, b;
vector <int> l, r;
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        l.push_back(a);
        r.push_back(b);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    if (n % 2 == 1){
        cout << r[n/2]-l[n/2]+1 << "\n";
    }
    else{
        cout << (r[n/2]+r[n/2-1])-(l[n/2]+l[n/2-1])+1 << "\n";
    }
}