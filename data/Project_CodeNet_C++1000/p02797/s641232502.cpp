#include <iostream>
#include <cstdio> 　　　　 //定义输入／输出函数
#include <stack>　　　　　 //STL 堆栈容器
#include <map>　　　　　　 //STL 映射容器
#include <vector>　　　　　//STL 动态数组容器
#include <string>　　　　　//字符串类
#include <iterator>        //STL迭代器
#include <cstdlib> 　　　　//定义杂项函数及内存分配函数
#include <cstring> 　　　　//字符串处理ed
#include<algorithm>
#include<queue>
#include<cmath>
#include<ctime>
#include<climits>
#include<iomanip>
#include<sstream>
using namespace std;
#define FOR(ITER,BEGIN,END)  for(int  ITER=BEGIN;ITER<END;ITER++)
#define PER(ITER,TIMES) FOR(ITER,0,TIMES)
#define TIME(TIME_NUMBER) PER(_PETER_MRSCO_ITER_,TIME_NUMBER)	
#define  ll  long long
#define close_stdin  ios::sync_with_stdio(false)
#define inf 0x3f3f3f3f
const int maxn = 100000;
void solve() {
	int n,m,sum;
	cin >> n>>m>>sum;
	if (sum == 1000000000) {
		n -= m;
		while (m--) { cout << 1000000000 << " "; }
		for (int i = 1;i <= n;i++) { cout << 1 << " "; }
		cout << "\n";
	}
	else {
		n -= m;
		while (m--) { cout << sum << " "; }
		for (int i = 1;i <= n;i++) { cout << sum + 1 << " "; }
		cout << "\n";
	}
}
int main() {
	close_stdin;
	solve();
}