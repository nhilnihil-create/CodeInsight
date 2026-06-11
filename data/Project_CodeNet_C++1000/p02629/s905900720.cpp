#include <bits/stdc++.h>
using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    cout << "print_vector -> ";
    for(int i=0; i<vec.size(); i++) {
        if(i == vec.size()-1) {
            cout << vec[i] << endl;
        }
        else {
            cout << vec[i] << " ";
        }
    }
    return;
}

vector<int> v;

void solve(int n) {
    if(n<=1) return;
    int l = sqrt(n);
    for(int i=2; i<=l; i++) {
        if(n%i==0) {
            solve(i); solve((int)(n/i)); return;
        }
    }
    v.push_back(n); return;
}

int main() {

    unsigned long long N;
    cin >> N;

    N--;
    string ans;
    while(1) {
        char name = 'a' + (N % 26);
        ans += name;
        N /= 26;
        if(N == 0) break;
        N--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}