#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <algorithm> 
#include <set>
#include <sstream>
#include <bit>
#include <bitset>
#include <iomanip>
#include <queue>
typedef long long int ll;
using namespace std;
int main() {
	ll N, A, B; cin >> N >> A >> B;
	ll sum = A + B;
	ll num,ans=0;
	num = (ll)N / sum;
	ll temp=N%(A+B);
	ll matubi;
	matubi = max((ll)0, temp - A);
	ans = N-B * num - matubi;
	cout << ans << endl;
}