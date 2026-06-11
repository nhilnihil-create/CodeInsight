#include <iostream>

int main(){
    using namespace std;
    int n, h, minimum;
    bool yes = true;
    cin >> n;
    cin >> minimum;
    minimum--;
    for (int i=0; i<n-1;i++){
        cin >> h;
        if (minimum > h){
            yes = false;
            break;
        }
        minimum = max(h - 1, minimum);
    }
    if (yes) cout << "Yes" << endl;
    else cout << "No" << endl;
}