#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    int n = int(S.size());
    vector<int> A(n,0);
    for (int i=0;i<n;i++) {
        int cnt = 0;
        if (S.at(i) == 'R') {
            while(S.at(i) == 'R') {
                i++;
                cnt++;
            }
            if (cnt % 2 == 0) {
                A.at(i) += (cnt/2);
                A.at(i-1) += (cnt/2);
            } else {
                A.at(i-1) += (cnt+1)/2;
                A.at(i) += cnt/2;
            }
        } 
    }
    for (int i=n-1;i>0;i--) {
        int cnt = 0;
        if (S.at(i) == 'L') {
            while(S.at(i) == 'L') {
                i--;
                cnt++;
            }
            if (cnt % 2 == 0) {
                A.at(i) += cnt/2;
                A.at(i+1) += cnt/2;
            } else {
                A.at(i+1) += (cnt+1)/2;
                A.at(i) += cnt/2;
            }
        }
    }
    for (int i=0;i<n;i++) {
        cout << A.at(i);
        if (i==n-1) cout << endl;
        else cout << " ";
    }
}