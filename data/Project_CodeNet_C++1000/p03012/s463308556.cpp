#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, w[110];
    int sum = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }

    int mini = sum;
    int s1 = 0, s2;
    for (int i = 0; i < n; i++) {
        s1 += w[i];
        s2 = sum - s1;
        mini = min(mini, abs(s1 - s2));
    }
    
    cout << mini << endl;
}