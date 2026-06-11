#include <iostream>
#include <algorithm>
#include <complex>
#include <vector>
using namespace std;
int main(){
    int n, a, b;
    cin >> n;
    bool flg_a = 0, flg_b = 0;
    vector<int> data_a(n);
    vector<int> data_b(n);
    vector<int> pmt(n);
    for (int i = 0; i < n; i++){
        cin >> data_a[i];
        pmt[i] = i+1;
    }
    for (int i = 0; i < n; i++){
        cin >> data_b[i];
    }
    int i = 1;
    do {
        if(data_a == pmt){
            a = i;
            flg_a = 1;
        }
        if(data_b == pmt){
            b = i;
            flg_b = 1;
        }
        if(flg_a && flg_b)break;
        i++;
    } while (next_permutation(pmt.begin(), pmt.end()));
 
    cout << abs(a - b) << endl;
    return 0;
}