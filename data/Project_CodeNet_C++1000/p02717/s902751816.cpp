#include <bits/stdc++.h>

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define eb emplace_back
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Vi = vector<int>;

void run() {
  	int a, b, c;
  	cin >> a >> b >> c;
  	swap(a, b);
  	swap(a, c);
  	cout << a << " " << b << " " << c << endl;
}

int main() 
{
    IO;
    double st = clock();
    run();
    cerr << "\n" << "time = " << (clock() - st) / CLOCKS_PER_SEC << "\n";
    return 0;
}