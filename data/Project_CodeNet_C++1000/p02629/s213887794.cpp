#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    vector<char> box = {'a','b','c','d','e','f',
    'g','h','i','j','k','l','m','n','o','p','q','r',
    's','t','u','v','w','x','y','z'};
    ll N;
    ll k;
    ll x;
    ll q,r;
    ll cnt = 0;
    cin >> N;
    int j = 1;
    while(N>0) {
        N = N - pow(26,j);
        j++;
    }
    j = j - 2; // j + 1 桁の数値になる
    vector<char> bufbox(j+1);
    k = N + pow(26,j+1);
    x = k - 1;
    //cout << j << endl;
    for(int i=0;i<j+1;i++) {
        bufbox.at(i) = 'a';
    }
    while(true) {
        q = x / 26;
        r = x % 26;
        x = q;
        //cout << r << endl; //0,1,...,r番目のアルファベット
        bufbox.at(j-cnt) = box.at(r);
        cnt++;
        if (x == 0) {
            break;
        }
    }
    for(int i=0;i<j+1;i++) {
        cout << bufbox.at(i);
    }
    cout << endl;
}