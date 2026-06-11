/*　　　　　　　{:i:i:|i:i:/l/l--　 　 　--l/li:i:i|i:i:i:i}
　　　　　　 　 {:rx|:i:i ィi芥ミ 　 　 .ィi芥ミｉ:ｉ|ﾍ:i:i:}
.　　　 　 　 　 ｛ﾏ|ｉ:  {::’:} 　 　 　{:‘::} :ｉ:i:|〉｝:/
　　 　 　 　 　 乂|:i:| ｀¨¨¨¨´ 　 　　｀¨¨¨´  :i:ｉ:|ｼ/
　 　 　 　 　 　 ﾉ:|:i|　　　　　　′　　　 　   |:i:i:|ﾂ
　　　　　　　　/:/|:i:| ､　　　 　_ _ 　　　　  |:i:i:|
　 　 　　 　 /:/ .|:i:|/ ＼　　　 　 　     ｨ〔|:i:/
　　 　 　  　 〈;/ く刈＿ 个 　   -   　＜}　./|/_〉
　　     　　 r-っ'~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ~ﾞ|___
　　 　     /／ニつ　　　　　　 ､　　　　　　　ノﾆﾆ　＼
.　　　     |　　ニ⊃ 　./　/　 ──   /　/　　..⊆ﾆﾆ　　:|
.　　　     |　　丁´　 /|￣|￣  ─‐ /|￣|￣ 　 .￣|丁 　|
.　　　     |　　ﾉ.  　 |￣|￣  ─‐  |￣|￣ 　 　.|八 　|
.　　　     |　　||. 　 |￣|￣ |￣| |￣|￣ 　   .|　|
.　 　 　   |  　||   　￣￣￣　￣ 　￣￣￣　　  .|　|  |
.　 　 　  　    ||＿＿＿＿＿＿＿＿＿＿＿＿______|__　　 ',
　 　      ,′　 | ７ﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆ}  ,′
.　　     {　　　|/　}ﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆﾆ{/ 　 　
*///讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐讐。
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <limits>

using namespace std;

#define rep(b) for(int i=0;i<int(b);i++)
#define ll long long
#define fst first
#define snd second
#define pf(b) printf("%.12f\n",(double)b)
#define _GLIBCXX_DEBUG
const double pai = 3.1415926535897;
#define _cos(n) cos(n*pai/180)
#define l_b lower_bound
#define u_b upper_bound
#define b_s binary_search

//factorial(練習)　階乗
int fact(int n) {
	int a = 1;
	for (int i = 1;i <= n;i++) a *= i;
	return a;
}
int sa(int n, int m) {      //差！
	if (n < m)return m - n;
	else return n - m;
}
int keta(int num) {
	int n = 0;
	if (num == 0) {
		return 1;
	}
	while (num != 0) {
		num /= 10;
		n++;
	}
	return n;
}

string s,t;
int ans;
signed main() {
	cin >> s >> t;
	int n = s.size();
	rep(n) {
		if (s[i] != t[i])ans++;
	}cout << ans << endl;
}