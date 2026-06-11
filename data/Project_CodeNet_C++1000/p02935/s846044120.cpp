#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());
    stack<double> s;
    for(int i = 0; i < n; i++) s.push(v[i]);
    while(s.size() != 1) {
        double x = s.top(); s.pop();
        double y = s.top(); s.pop();
        s.push((x+y)/2);
    }
    cout << s.top() << endl;
    return 0;
}