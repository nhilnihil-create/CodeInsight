#include <iostream>
using namespace std;

int main(){
    int n;
    int d[2][101];
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> d[0][i] >> d[1][i];
    }
    for (int i = 0; i < n; i++){
        if (d[0][i] == d[1][i] && d[0][i+1] == d[1][i+1] && d[0][i+2] == d[1][i+2]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}