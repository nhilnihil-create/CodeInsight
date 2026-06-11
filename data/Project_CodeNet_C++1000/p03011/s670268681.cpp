#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int answer;
    vector<int> PQR(3);
    cin >> PQR.at(0) >> PQR.at(1) >> PQR.at(2);
    sort(PQR.begin(), PQR.end());
    answer = PQR.at(0) + PQR.at(1);
    cout << answer << endl;
}