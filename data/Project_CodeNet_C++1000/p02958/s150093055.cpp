#include <iostream>

using namespace std;

int main(){
    int n = 0;
    cin >> n;  
    int difference = 0;

    for (int i=0 ;i<n; ++i){
        int x = 0;
        cin >> x;
        if (x != i+1){
            difference++;
        }
    }

    cout << (difference > 2 ? "NO" : "YES") << "\n";
    return 0;
}