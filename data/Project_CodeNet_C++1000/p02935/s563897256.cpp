#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<double> v(N);

    for(int i = 0; i < N; i++){
        cin >> v.at(i);
    }

    double sum = 0.0;
    sort( v.begin(), v.end());

    sum = (v.at(0) + v.at(1))/2;

    for(int i = 2; i < v.size(); i++){
        sum = (sum + v.at(i))/2;
    }

    cout << sum << endl;

}