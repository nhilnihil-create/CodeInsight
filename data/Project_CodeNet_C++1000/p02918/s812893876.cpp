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


/*											 
 LまたはRが連続する区間を調べ上げる。たとえばLLRRRRRRRRRRRRRRRLLについて、不幸な人間の数は
											 ^　             ^^  
矢印で示した3人である。ここで、Rで構成された区間をflipする。LLLLLLLLLLLLLLLLLLL
不幸な人は2人減ったことになる。ここで増減分はR区間の長さで変化しない。
LLRRLL		->Rの区間が2人以上 := -2
LLRLL		->Rの区間が1人だけ := -2

LとRを交換した状況を考える。

RRLLRR		->Lの区間が2人以上 := -2
RRLRR		->Lの区間が1人だけ := -2

やはり同じである。

またflipする区間が端っこである場合は増減が変化する

 LLRRLL  -> RRRRLL := -1(左端が救われた)
 LLRRLL  -> LLRRRR := -1(右端が不幸になったので2人減らすことはできなかった)
 
 RRLLRR  -> LLLLRR := -1(左端が不幸になったので2人減らすことはできなかった)
 RRLLRR  -> RRLLLL := -1(右端が救われた)


 以上を踏まえれば、端でない区間のflipを繰り返して不幸な人間を2人ずつ減らしていくことが最適な行為である。
 回数が余ってしまった場合は端を修正することでさらに減らすことができる。
 実際flipによって減った区間数が不幸な人間の減少数と一致する
 つまり最終的な幸福数は実はO(1)で求めることができ、必要なのは区間数を調べ上げるO(N)の計算が支配的になる。

 LLRR -> LLLL
 LLRR -> RRRR 
 RRLL -> RRRR
 RRLL -> LLLL

 どうやったって-1にしかならない。ありがたい。

 span数と不幸な人間の数は一意に対応するだろうか。
*/

void D() {
	read(int, n);
	read(int, k);
	int unhappy = 0;
	char prev; char c = '!'; cin >> prev;
	if (prev == 'L')unhappy++;
	for (size_t i = 1; i < n; i++) {
		cin >> c;
		if (c == 'L' && prev == 'R') unhappy += 2;
		prev = c;
	}
	if (c == 'R')unhappy++;//最後の人が右を向いていれば不幸
	for (size_t i = 0; i < k; i++) {
		if (unhappy > 2) unhappy -= 2;
		else if (unhappy == 2)unhappy--;
		else break;
	}
	cout << n - unhappy << endl;
}

int main() { D(); }

void E() {

}
void F() {

}

