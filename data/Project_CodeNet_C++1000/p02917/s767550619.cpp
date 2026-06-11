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
 Bi>=max(Ai,A+1)が必ず満たされる。例えばB0はmax(A0,A1)以上の数字である。逆に言えば、A0とA1は最大でB0ということになる。
 となればA0とA1がともにB0であるとすれば最大である。一方で、B1がB0よりも小さい場合、A1はB1よりも小さくなければならないので
 A1をB0としてはならない。結局、Aiはmin(Bi-1,Bi)というのが最大になる。これを繰り返せばよい。O(n)の解法である。
*/
void C() {
	read(int, n);
	auto B = vector<int>(n - 1);
	rep(i, n - 1) cin >> B[i];
	int prevB = 100000000;
	int currentB;
	auto sum = 0;
	rep(i, n - 1) {
		currentB = B[i];
		sum += min(prevB, currentB);
		prevB = currentB;
	}
	//ラストはB１つで決まる。
	sum += currentB;
	cout << sum << endl;
}
void D() {

}
void E() {

}
void F() {

}



int main() {
	C();
}