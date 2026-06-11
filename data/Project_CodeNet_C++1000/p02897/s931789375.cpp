#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <climits>
using namespace std;

#define MOD1097 1000000007

#define ll long long
#define pint pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mpair make_pair
#define pm(first, second) pb(mpair(first, second))
#define SPACE " "
#define fpf first.first
#define fps first.second
#define spf second.first
#define sps second.second

#define all(X) (X).begin(), (X).end()
#define reall(X) (X).rbegin(), (X).rend()
#define divcel(a, b) (((a) + ((b) - 1)) / (b))

int main(){

	int N;
	cin >> N;
	if(N%2 == 0){
		cout << "0.5" << endl;
	}
	else{
		printf("%0.7lf\n", ((double)(N/2)+1.0)/(double)N);
	}

	return 0;
}
