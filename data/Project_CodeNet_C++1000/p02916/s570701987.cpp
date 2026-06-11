#pragma once
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>
#include <iomanip>
#define rep(i,n) for(auto i=0;i<(n);i++)
#define all(vs) (vs).begin(),(vs).end()
#define roundup(A,B) (A)/(B)+((A)%(B)==0?0:1)
#define read(type,name) type name;cin>>name
using namespace std;


/*
	3桁の数字からなる、重複を許す数字列はN^3パターンになる。O(1)
*/
void A() {
	read(int, i);
	cout << i * i * i << endl;
}

/*
 次の数字が連番である場合、追加でスコアが入る。そのため、直前の数字を記憶する必要がある。
 あとは情報を読み込んで配列を走査すればよい。空間量は今回削減できないと思われる。
*/
void B() {
	read(int, n);
	auto dishes = vector<int>(n);
	auto scores = vector<int>(n);
	auto bonus = vector<int>(n - 1);
	rep(i, n) cin >> dishes[i];
	rep(i, n) cin >> scores[i];
	rep(i, n - 1) cin >> bonus[i];
	auto prev = -1;
	int current;
	int result = 0;
	rep(i, n) {
		current = dishes[i];
		result += scores[current - 1];
		if (prev + 1 == current) result += bonus[prev - 1];
		prev = current;
	}
	cout << result << endl;
}

/*
*/
void C() {

}
void D() {

}
void E() {

}
void F() {

}



int main() {
	B();
}	
										