#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<iomanip>
#include<iostream>
using namespace std;

#define PI 3.1415926535

typedef struct {
    double x;
    double y;
} POINT;

vector<POINT> plist;

void kock(int n, POINT p1, POINT p2)
{
    if (n == 0) return;
    POINT s, t, u;
    s = POINT{(p1.x * 2 + p2.x) / 3, (p1.y * 2 + p2.y) / 3};
    t = POINT{(p1.x + p2.x * 2) / 3, (p1.y + p2.y * 2) / 3};
    u = POINT{
        (t.x - s.x) * cos(PI / 3) - (t.y - s.y) * sin(PI / 3) + s.x,
        (t.x - s.x) * sin(PI / 3) + (t.y - s.y) * cos(PI / 3) + s.y
    };

    kock(n-1, p1, s);
    plist.push_back(s);
    kock(n-1, s, u);
    plist.push_back(u);
    kock(n-1, u, t);
    plist.push_back(t);
    kock(n-1, t, p2);
}

int main(int, char**)
{
    int n;
    cin >> n;

    POINT s = POINT{0.0f, 0.0f};
    POINT e = POINT{100.0f, 0.0f};
    plist.push_back(s);
    kock(n, s, e);
    plist.push_back(e);
    cout << setprecision(10);
    for (POINT p : plist)
        cout << p.x << " " << p.y << endl;

    return 0;
}
