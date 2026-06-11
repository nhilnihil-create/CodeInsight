#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map> 
#include <unordered_set>
#include <set>
#include <functional>
#include <utility>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
#define mod 1000000007
#define for0(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define forA(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define forD(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define pb push_back 
#define pob pop_back
#define mp make_pair

typedef long long int            ll;
typedef vector<int>              vi;
typedef pair<int, int>           pi;
typedef unordered_map<int, int>  mii;
typedef unordered_map<char, int> mci;
typedef unordered_set<int>       usi;

void solve(){
	int a;
	cin>>a;
	string s;
	cin>>s;

	if(a < 3200)
		cout<<"red"<<endl;
	else cout<<s<<endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1; 
    // cin>>t;
    while(t--){
      solve();
    }
    return 0;
}