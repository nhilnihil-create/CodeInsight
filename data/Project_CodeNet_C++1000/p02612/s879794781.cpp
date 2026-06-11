#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define eps 1e-9
#define inf 0x3f3f3f
#define mod 4999999
using namespace std;
 
int main() {
	speed;
    int n;
    cin >> n;
    cout << (1000 - n % 1000) % 1000;
}