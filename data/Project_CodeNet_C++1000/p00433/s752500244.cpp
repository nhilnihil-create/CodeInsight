
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0510

#include <algorithm>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//テ」ツδ榲」ツつッテ」ツδュテ・ツョツ堙ァツセツゥ
#define ALL(v) (v).begin(),(v).end()
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define REP(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define SORT(x) sort(begin(x),end(x))
#define SELECT_SORT(x, n) sort(begin(x),begin(x)+n)
#define SWAP(type, a, b) do {type tmp = a; a = b; b = tmp;} while (0)
#define rep_split(tok,a_str,re) for(char *tok = strtok((char *)a_str.c_str(),re); tok != NULL; tok = strtok(NULL,re))

//テ・ツョツ堙ヲツ閉ー
#define INF 2000000000000
#define MAX 10

//DEBUGテァツ板ィ
#define BAR() cout << "----------------------------" << endl;
#define DUMP(v) (cerr << #v << ": " << v << endl)
#define PRINT(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;


int main()
{
	int a[]={0};
	int b[]={0};
	int S= 0;
	int T=0;
	
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	cin >> b[0] >> b[1] >> b[2] >> b[3];
	
	rep(i,4){
		S += a[i];
		T += b[i];
	}
	
	if(S >= T){
		cout << S << endl;
	}else{
		cout << T << endl;
	}
	
}