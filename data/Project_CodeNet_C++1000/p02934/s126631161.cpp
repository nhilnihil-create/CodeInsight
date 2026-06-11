#include <bits/stdc++.h>
#define ll long long int
#define booga cout << "booga" << endl
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void testcase(){

}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	double curr = 0,inp;
	while(n--){
		cin >> inp;
		curr += 1 / inp;
	}
	cout << fixed << setprecision(5) << 1 / curr << "\n";
	return 0;
}

