#include <iostream>
using namespace std;

int main() {
    int h, n, a;
    cin >> h >> n;
    bool flag = false;
    for(int i = 0; i < n; i++){
        cin >> a;
        h -= a;
        if(h <= 0){
            cout << "Yes";
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "No" << endl;
    return 0;
}