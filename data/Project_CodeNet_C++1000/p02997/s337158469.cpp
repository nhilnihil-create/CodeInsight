#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n,k;
	cin >> n >> k;
	if(k > (n - 1) * (n - 2) / 2)cout << -1 << '\n';
	else{
		vector<P> edge;
		edge.push_back(P(1,2));

		//1をウニの中心にする.
		//3~Nを追加していく.
		int sum = 0;
		int v_num = 0;//3からスタートして何頂点分までウニにするか.
		for(int i = 1;;i++){
			if(sum + i > k)break;
			sum += i;
			v_num = i;
		}

		for(int i = 3;i <= n;i++){
			if(v_num){
				edge.push_back(P(i,1));
				v_num--;
				k -= (i - 2);
			}
			else{
				if(k){
					edge.push_back(P(i,1));
					for(int j = 1;j <= (i - 2) - k;j++){
						edge.push_back(P(j+1,i));
					}
					k = 0;
				}
				else{
					for(int j = 1;j < i;j++){
						edge.push_back(P(j,i));
					}
				}
			}
		}

		cout << edge.size() << endl;
		for(auto e:edge){
			cout << e.first << " " << e.second << endl;
		}
	}
}
