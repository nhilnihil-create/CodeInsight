#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long int n = 0, a = 0, sum = 0;
    
    vector<long long> persoane;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        persoane.push_back(a);
    }
    for (int i = 0; i < n-1; i++) {
        if (persoane[i] <= persoane[i + 1]) {
            sum += 0;
        }
        else {
            sum += (persoane[i] - persoane[i + 1]);
            persoane[i + 1] = persoane[i];
        }
    }
    cout << sum;
    return 0;
}