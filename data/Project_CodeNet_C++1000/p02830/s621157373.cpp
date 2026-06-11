#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int x = 0; x < n; x++){
        cout << s.at(x) << t.at(x);
    }
    cout << endl;
}
 