#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    int h = t / 3600;
    t -= h*3600;
    int m = t / 60;
    t -= m*60;
    int s = t;
    cout << h << ":" << m << ":" << s << endl;
}
