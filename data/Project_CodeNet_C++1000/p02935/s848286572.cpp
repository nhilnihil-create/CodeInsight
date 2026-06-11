#include<bits/stdc++.h>
using namespace std;

int main() {
    int N; 
    cin >> N;
    vector <double> v(N);
    for (int i=0; i<N; i++) {
        cin >> v.at(i);
    }
    sort(v.begin(), v.end());
    for (int i=0; i<N-1; i++) {
        v.at(i+1) = (v.at(i)+v.at(i+1))/2.0;
    }
    cout << v.at(N-1);
}