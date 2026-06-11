#include<bits/stdc++.h>

using namespace std;

int exclamation(int num) {
    if(num == 1) {
        return 1;
    } 

    return num * exclamation(num-1);
}

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    vector<int> town(N);
    double length = 0;
    double sum = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        town[i] = i;
    }

    do {
        length = 0;

        for(int i = 0; i < N-1; i++) {
            length += sqrt(pow(double(x[town[i]] - x[town[i+1]]), 2.0) + pow(double(y[town[i]] - y[town[i+1]]), 2.0));
        }

        sum += length;

    } while(next_permutation(town.begin(), town.end()));

    sum /= double(exclamation(N));

    cout << fixed << setprecision(10) << sum << endl;
	return 0;
}