#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> vec1(n);
    long long tgt = 0;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec1.at(i);
        if (tgt >= vec1.at(i)){
            res += tgt - vec1.at(i);
        } else {
            tgt = vec1.at(i);
        }
    }
    cout << res;
}
