#include <bits/stdc++.h>
#include <iostream>
#include <math.h>    //pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm> //sort(a.begin(), a.end());reverse(a.begin(), a.end());
#define rep(init, i, n) for (int i = init; i < (n); i++)
#define ll long long
#define rev(s) reverse(s.begin(), s.end())
#define sor(v) sort(v.begin(), v.end())
#define PI 3.14159265358979323846264338327950
//コード自動整形 Shift + Option + F @vscode
using namespace std;

/////main/////
int main()
{
    double A, B, H, M;
    cin >> A >> B >> H >> M;
    long double rad = 2 * PI * ((H * 30) + (M * 0.5) - 6 * M) / 360;

    long double output = sqrt(A * A + B * B - 2.0 * A * B * cos(rad));

    cout << fixed << setprecision(10)<< output << endl;
}
/////main/////

/////function/////