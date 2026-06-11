#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    set<int> s{1,2,3};
    s.erase(a);
    s.erase(b);
    auto x = s.begin();
    cout << *x << endl;
}
