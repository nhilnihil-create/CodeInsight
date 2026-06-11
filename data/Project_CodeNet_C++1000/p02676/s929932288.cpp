#include<iostream>
#include<cstring>
using namespace std;
double eps = 1e-5;
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(s.size() <= n) cout << s;
    else {
        for (int i = 0; i < n; i++) cout << s[i];
        cout << "..."; 
    }
}