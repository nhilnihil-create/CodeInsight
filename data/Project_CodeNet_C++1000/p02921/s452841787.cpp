#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;
const int IINF = INT_MAX;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000000000
int n;

int main(){
    string s,t;
	cin >> s >> t;
	
	int count = 0;
	
	rep(i,3){
    	if(s[i] == t[i]) count++;
    }
	
	cout << count <<endl;
	
    
    return 0;	
}