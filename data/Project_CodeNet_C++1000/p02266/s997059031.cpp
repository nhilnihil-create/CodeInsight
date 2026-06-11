#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<numeric>
#include<stdio.h>

using std::cout;
using std::cin;
using std::setw;
using std::setfill;
using std::string;
using std::pair;
using std::make_pair;
using std::vector;
using std::queue;
using std::deque;
using std::priority_queue;
using std::next_permutation;
using std::iota;
using std::sort;
using std::greater;
using std::max;
using std::min;

#define INF 999999999
#define MOD 1000000007

#define EVEL 1

#ifndef EVEL
#define dbug(X) std::cout << #X << ":" <<X<<" " ;
#define dbugf(s) std::cout << s << " ";
#define dbugln std::cout<<"\n";
#else
#define dbug(X) {}
#define dbugf(s) {}
#define dbugln {}
#endif

struct w{
	int Beg;
	int End;
	int siz;
};

string s;
vector<int> c;
w ipt;
vector<w> cc;
vector<int> answer;
w maxim = {0, 0, 0};
int A;


int main(){
	cin.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '\\'){
			c.push_back(i);
		}else if(s[i] == '/'){
			if(!c.empty()){
				ipt.Beg = c.back();c.pop_back();
				ipt.End = i;
				ipt.siz = ipt.End - ipt.Beg;
				dbug(ipt.Beg)dbug(ipt.End)dbug(ipt.siz)dbugln;
				cc.push_back(ipt);
			}
		}
	}
	sort(cc.begin(), cc.end(), [](w a, w b){return (a.Beg < b.Beg);});
	for(auto i = cc.begin();i != cc.end(); ++i){
		dbug(i->Beg)dbug(i->End)dbug(i->siz)dbugln;
		dbug(maxim.Beg)dbug(maxim.End)dbug(maxim.siz)dbugln;
		if(maxim.End <= i->Beg){
			if(maxim.siz != 0){
				A+=maxim.siz;
				answer.push_back(maxim.siz);
			}
			maxim = *i;
		}else if(maxim.End >= i->End){
			maxim.siz += i->siz;
		}
	}
	if(maxim.siz != 0){
		A+=maxim.siz;
		answer.push_back(maxim.siz);
	}
	cout << A << "\n";
	cout << answer.size();if(answer.size() != 0)cout << " ";
	for(int i = 0; i  < answer.size(); ++i){
		cout << answer[i];
		if(i != answer.size()-1) cout << " ";
	}
	cout << "\n";
	return 0;
}

