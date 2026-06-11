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
	string a, b, temp;
	cin >> a >> b;
	int no_a, no_b;
	cin >> no_a >> no_b;
	while(cin >> temp) {
		if(temp == a) no_a--;
		if(temp == b) no_b--;
	} 
	cout << no_a << " " << no_b << endl;
}

int main() 
{
    IO;
    double st = clock();
    run();
    cerr << "\n" << "time = " << (clock() - st) / CLOCKS_PER_SEC << "\n";
    return 0;
}