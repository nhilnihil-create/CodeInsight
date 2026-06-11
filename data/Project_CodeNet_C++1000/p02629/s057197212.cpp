#include <iostream>
using namespace std;
int main () {
    long long int N;
    cin >> N;
    long long int exp=0, c, sum=26;
    for (int i=1; i<=10000; i++) {
        if (i==2) {
            exp=26*26;
        }
        else {
            exp*=26;
        }
        if (N<=sum+exp) {
            c=i;
            break;
        }
        sum+=exp;
    }
    sum=1, exp=26;
    long long int s;
    for (int i=1; i<=10000; i++) {
        if (c==i) {
            s=N-sum;
            break;
        }
        sum+=exp;
        exp*=26;
    }
    string ans;
    for (int i=0; i<c; i++) {
        ans.push_back(s%26+97);
        s/=26;
    }
    for (int i=ans.size()-1; i>=0; i--) {
        cout << ans[i];
    }
}