
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <complex>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
using namespace std;
const int dx[]={1,0,-1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,1,1,-1,-1};
const int INF = 1<<30;
const int EPS = 1e-15;
#define PB push_back
#define fi first
#define se second
#define ll long long
#define reps(i,j,k) for(int i = (j); i < (k); i++)
#define rep(i,j) reps(i,0,j)
#define MOD 1000000007
typedef pair<int,int> Pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int > Pii;
int main(){
	while(true){
		string str;
		getline(cin,str);
		if(str.size() == 1 && str == ".")break;
		stack<char> state;
		bool flg = true;
		rep(i,str.size()){
			if(str[i] == '(' || str[i] == '['){
				state.push(str[i]);
			}
			else if(str[i] == ')'){
				if(state.size()==0 || state.top() != '('){
					flg =  false;
					break;
				}
				else{
					state.pop();
				}
			}
			else if(str[i] == ']'){
				if(state.size()==0 || state.top() != '['){
					flg =  false;
					break;
				}
				else{
					state.pop();
				}
			}
		}
		if(state.size() != 0)flg = false;
		flg ? puts("yes") : puts("no");
	}
	return 0;
}