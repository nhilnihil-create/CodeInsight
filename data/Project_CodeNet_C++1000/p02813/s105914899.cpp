#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> p(n),q(n);
    for(int i=0;i<n;i++) {
        cin >> p[i];
    }       
    for(int i=0;i<n;i++) {
        cin >> q[i];
    }
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        v[i] = i+1;
    }
    int cnt = 0;
    int a = -1,b = -1;
    do {
        cnt++;
        if(v == p) {
            a = cnt;
        } 
        if(v == q) {
            b = cnt;
        }
        if(a != -1 && b != -1) {
            break;
        }
    } while(next_permutation(v.begin(),v.end()));
    cout << abs(a-b) << "\n"; 
}