#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    long n;
    cin >> n;
 
    vector<long long> p(n);
    for (auto &x : p) {
        cin >> x;
    }
 
    vector<long long> q(n);
    for (auto &x : q) {
        cin >> x;
    }
 
    vector<long long> tmp = p;
 
    sort(tmp.begin(), tmp.end());
 
    long long ip = 0;
    long long iq = 0;
    long long index = 0;
    do {
        if (p == tmp) {
            ip = index;
        }
        if (q == tmp) {
            iq = index;
        }
        index++;
 
    }while(next_permutation(tmp.begin(), tmp.end()));

    cout << abs(ip - iq) << endl;
}