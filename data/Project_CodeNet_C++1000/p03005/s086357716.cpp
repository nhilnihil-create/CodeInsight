#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
	int n,k;
    cin >> n >> k;
    if(k == 1){
        cout << 0 << endl;
    }else{
        cout << n - k << endl;
    }
}