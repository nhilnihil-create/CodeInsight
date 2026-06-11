#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> X(n);
    int ave1,ave2,sum = 0;
    for (int i = 0; i < n ; i ++){
        cin >> X.at(i);
        sum += X.at(i);
    }
    ave1 = sum / n;
    ave2  =sum / n + 1;
    int sum1 = 0,sum2 = 0;
    for (int j = 0; j < n ; j ++){
        sum1 += pow(ave1 - X.at(j),2);
        sum2 += pow(ave2 - X.at(j),2);
    }
    cout << min(sum1,sum2) << endl;
}
