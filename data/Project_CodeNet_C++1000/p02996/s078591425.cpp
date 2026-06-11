#include <bits/stdc++.h>
using namespace std;
 
int main() {

    int N;
    cin >> N;

    vector<pair<int, int>> A(N);

    for(int i = 0; i < N; i++){
        cin >> A.at(i).second >> A.at(i).first;
    }

    long long now = 0;

    sort(A.begin(), A.end());

    for(int i = 0; i < N; i++){
        now += A.at(i).second;
        if(now > A.at(i).first){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

}