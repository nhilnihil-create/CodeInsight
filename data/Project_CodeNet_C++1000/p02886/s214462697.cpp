#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int n, sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    cin >> n;
    int list[n];
    for (int x = 0; x < n; x++){
        cin >> list[x];
    }
    for (int x = 0; x < n; x++){
        sum1 += list[x] * list[x];
        for (int i = 0; i < n ; i++){
            sum2 += list[x] * list[i];
        }
    }
    cout << (sum2 - sum1) / 2 << endl;
}