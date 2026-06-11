#include <bits/stdc++.h>
using namespace std;

int main() {
	int s,w;
    cin >> s >> w;
    string a = "unsafe";
    if(s > w){
      a = "safe";
    }
    cout << a << endl;
}
