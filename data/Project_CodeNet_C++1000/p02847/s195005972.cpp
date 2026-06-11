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

	string S;
	cin >> S;
	if(S == "SUN")cout << "7" << endl;
	if(S == "MON")cout << "6" << endl;
	if(S == "TUE")cout << "5" << endl;
	if(S == "WED")cout << "4" << endl;
	if(S == "THU")cout << "3" << endl;
	if(S == "FRI")cout << "2" << endl;
	if(S == "SAT")cout << "1" << endl;

	return 0;
}
