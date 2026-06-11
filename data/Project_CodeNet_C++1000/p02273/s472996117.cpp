#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
typedef long long ll;


void koch(int d, pair<float, float> left, pair<float, float> right){
    if(d == 0){
        return;
    }else{
        d--;
    }
    pair<float, float> s, t, u;

    s.first  = (right.first + 2 * left.first) / 3;
    // cout << right.first << " " << left.first << " " << s.first << endl;
    s.second = (right.second + 2 * left.second) / 3;

    t.first  = (2 * right.first + left.first) / 3;
    t.second = (2 * right.second + left.second) / 3;

    float tmpx = t.first - s.first;
    float tmpy = t.second - s.second;
    u.first  = tmpx / 2 - sqrt(3) / 2 * tmpy + s.first;
    u.second = sqrt(3) / 2 * tmpx + tmpy / 2 + s.second;

    koch(d, left, s);
    printf("%f %f\n", s.first, s.second);

    koch(d, s, u);
    printf("%f %f\n", u.first, u.second);

    koch(d, u, t);
    printf("%f %f\n", t.first, t.second);

    koch(d, t, right);
    // printf("%f %f\n", right.first, t.second);
    return;

}

int main(){
    int n; cin >> n;
    pair<float, float> right, left;
    left.first = 0;
    left.second = 0;
    right.first = 100;
    right.second = 0;

    // cout << left.first << " " << left.second << endl;
    printf("%f %f\n", left.first, left.second);
    koch(n, left, right);
    printf("%f %f\n", right.first, right.second);
    return 0;

}
