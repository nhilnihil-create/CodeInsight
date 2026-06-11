#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>


using namespace std;

int main() {
    long long int N, tmp, sum=0, left=0, dif = 2020202021;
    vector<int> A;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A.push_back(tmp);
        sum += tmp;
    }


    for (int i = 0; i < N; i++) {
        left += A[i];
        tmp = abs(sum - 2 * left);
        if (dif > tmp) {
            dif = tmp;
        }
    }

    cout << dif;

    return 0;
}