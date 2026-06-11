#include <bits/stdc++.h>
#define ll long long
#define sz size
#define pb push_back
#define mper make_pair
#define all(x) x.begin(), x.end()
#define fe first
#define se second
#define erba continue
using namespace std;

ll n, a, b, c, d;

string s;

void check1() {

    ll cnt = 0;

    for(int i = b - 1; i < d; ++i) {

        if(s[i] == '.') {

            cnt = 0;

        }

        else {cnt++;}

        if(cnt >= 2) {cout << "No";return;}
    }

    s[d - 1] = '#';

    cnt = 0;

    for(int i = a - 1; i < c; ++i) {

        if(s[i] == '.') {

            cnt = 0;

        }

        else {cnt++;}

        if(cnt >= 2) {cout << "No";return;}

    }

    cout << "Yes";


}

void check2() {

    bool check = 0;

    for(int i = b - 1; i < min(c, d); ++i) {

        if(s[i] == '.' && s[i - 1] == '.' && s[i + 1] == '.') {check = 1; a = i + 2; b = i + 1;}

    }

    if(a > b) {

        swap(a, b);
        swap(c, d);

    }


    if(!check) {cout << "No";return;}
    else {check1();}

}

int main() {

    cin >> n >> a >> b >> c >> d;

    cin >> s;

    if(s[a - 1] == '#' || s[b - 1] == '#' || s[c - 1] == '#' || s[d - 1] == '#') {cout << "No";return 0;}
    
    if(c < a || d < b) {cout << "No";return 0;}
    
    if(a > b) {

        swap(a, b);
        swap(c, d);

    }


    if(c < d) {check1();}
    else {check2();}

return 0;
}


