#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    int total=0;
    for(int i=0;i<n;i++){
        cin >> s.at(i) >> t.at(i);
        total+=t.at(i);
    }
    string x;
    cin >> x;
    int com=0;
    for(int i=0;i<n;i++){
        com+=t.at(i);
        if(x==s.at(i)){
            break;
        }
    }
    cout << total-com << endl;
}