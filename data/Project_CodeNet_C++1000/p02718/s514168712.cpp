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
 	int m, n;
 	cin >> m >> n;
 	Vi ara(m);
 	int sum = 0;

 	for (auto& I : ara) {
 		cin >> I;
 		sum += I;
 	}
 	bool ok = 1;
 	int cnt = 0;
 	double need = (sum*1.0)/ (4*n);
 	for (auto i : ara) {
 		if((double)i < need) {
 			ok = 0;
 			// break;
 		}
 		else cnt ++;
 	}

 	cout << (cnt >= n? "Yes" : "No")  << endl;
}

// y > x/z;
// yz < x;

int main() 
{
    IO;
    double st = clock();
    run();
    cerr << "\n" << "time = " << (clock() - st) / CLOCKS_PER_SEC << "\n";
    return 0;
}