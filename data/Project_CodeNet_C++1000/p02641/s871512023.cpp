#include <bits/stdc++.h>          
using namespace std;               

int main() {
    //
    int X,N;
    cin >> X >> N;
    
    if (N==0) {
        cout << X << endl;
        exit(0);
    }
    
    vector<int> p(N);
    for (int i=0; i<N; i++) {
        cin >> p.at(i);
    }
    sort(p.begin(),p.end());

    //
    vector<int> num;
    for (int i=0; i<=101; i++) {
        for(int j=0; j<N; j++) {
            if (i == p.at(j)) {
                break;
            }
            if (j == N-1) {
                num.push_back(i);
            }
        }
        
    }

    //
    vector<int> d(num.size());
    for (int i=0; i<num.size(); i++) {
        d.at(i) = abs(X-num.at(i));
    }
    sort(d.begin(),d.end());

    //
    for (int i=0; i<d.size(); i++) {
        if (num.at(i) == X-d.at(0)) {
            cout << X-d.at(0) << endl;
            exit(0);
        }
    }
    cout << X+d.at(0) << endl;
}