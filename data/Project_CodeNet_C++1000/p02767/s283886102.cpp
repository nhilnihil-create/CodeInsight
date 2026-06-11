#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> sum(102);

    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    
    for(int p = 0; p <= 101; p++){
        for(int i = 0; i < n; i++){
            sum[p] += ((x[i] - p) * (x[i] - p));
        }
    }
    sort(sum.begin(), sum.end());
    cout << sum[0] << endl;
}

