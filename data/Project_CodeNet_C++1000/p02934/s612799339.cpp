#include <iostream>
#include <string>
#include <vector>

#define mod 1000000000+7;
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin >> n;
	double sum;
	for(int i{}; i<n; i++){
		double z; cin >> z;
		sum+=1/z;
	}

	cout << 1/sum << "\n";
}