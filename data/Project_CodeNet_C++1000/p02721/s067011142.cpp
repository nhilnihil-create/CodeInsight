//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N,K,C;
string S;

vector<LL> ans;

void solve(){
	if(N==1){
		if(S[0]=='o') ans.push_back(1);
		return;
	}
	//前から貪欲に詰めたとき、i日目の時点での働ける日にちの最大値
	vector<LL> forward(N,0);
	//後ろから貪欲に詰めたとき、N-1-i日目の時点での働ける日にちの最大値
	vector<LL> backward(N,0);

	int counter_forward = 0;//労働日数のカウンタ
	int counter_backward = 0;//労働日数のカウンタ
	int counter_forward_waittime = C;//間隔調整用カウンタ
	int counter_backward_waittime = C;//間隔調整用カウンタ
	for(int i=0;i<N;i++){
		{
			counter_forward_waittime++;
			if(counter_forward_waittime>=C+1 && S[i]=='o'){
				counter_forward_waittime = 0;
				counter_forward++;
			}
			forward[i] = counter_forward;
		}
		{
			counter_backward_waittime++;
			if(counter_backward_waittime>=C+1 && S[N-1-i]=='o'){
				counter_backward_waittime = 0;
				counter_backward++;
			}
			backward[N-1-i] = counter_backward;
		}
	}

	// for(int i=0;i<N;i++){
	// 	cout << forward[i] << " ";
	// }
	// cout << endl;
	// for(int i=0;i<N;i++){
	// 	cout << backward[i] << " ";
	// }
	// cout << endl;

	if(backward[1]<K && S[0]=='o'){
		ans.push_back(0+1);
	}

	//i日目を労働不可と仮定しても
	//K日以上労働日数を確保できるならば
	//i日目は必ず働く日ではない
	//つまり
	//i日目を労働不可と仮定すると
	//K日未満しか労働日数が確保できないならば
	//i日目は必ず働く日
	C = max(C,1LL);
	multiset<LL> days;
	for(int i=1;i<N;i++){
		//新たな数を追加
		{
			if(i-1>=0 && i+C<N){
				LL sum = forward[i-1] + backward[i+C];
				days.insert(sum);
				// cout << "add:"<< sum << endl;
			}
		}

		LL day = 0;
		if(days.size()>0){
			day = (*(--days.end()));
		}
		if(i+1<N) day = max(day,backward[i+1]);
		if(i-1>=0) day = max(day,forward[i-1]);
		if(day<K){
			if(S[i]=='o') ans.push_back(i+1);
		}

		//不要になった数を削除
		{
			if(i-C>=0 && i+1<N){
				LL sum = forward[i-C] + backward[i+1];
				auto iter = days.lower_bound(sum);
				days.erase(iter);
				// cout << "erase:"<< (*iter) << endl;
			}
		}
		// cout << "i="<<i << endl;
		// for(auto iter=days.begin();iter!=days.end();iter++){
		// 	cout << (*iter) << " ";
		// }
		// cout << endl;
	}
}

int main(){
    cin >> N >> K >> C;
    cin >> S;

    solve();

    for(int i=0;i<ans.size();i++) cout << ans[i] << endl;
    return 0;
}