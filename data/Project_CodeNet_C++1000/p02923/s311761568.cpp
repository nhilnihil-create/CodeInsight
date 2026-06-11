#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define rep(i,n) for(auto i=0;i<(n);i++)
#define all(vs) (vs).begin(),(vs).end()
#define roundup(A,B) (A)/(B)+((A)%(B)==0?0:1)
using namespace std;


/*
  予想と答えをすべて比較するのが最速。O(n)
*/
void A() {
	string s, t;
	cin >> s >> t;
	int answer = 0;
	rep(i, s.length()) {
		if (s[i] == t[i])answer++;
	}
	cout << answer << endl;
}

/*
  タップを使うごとにA-1ずつ増える。Bと1の距離をA-1で割った（切り上げ）のが答え。
  A,Bの値によらないのでO(1)の解法である。
*/
void B() {
	int A, B; cin >> A >> B;
	cout << roundup(B-1, A-1) << endl;
}

/*
  左から走査することで最大長を求めることができる。最大長を0で初期化し、
  左端からスタートする。右に進める限り現在の長さをincrementし、進めなくなったところで最大長を更新する。
  そして止まったところからリセットして再開する。これを繰り返すことで最大長を求めることができる。
  計算量はO(n)、空間量はO(1)となる。
*/
void C() {
	int n; cin >> n;
	int length = 0, max_length = 0;
	int prev = 0, current;
	rep(i, n) {
		cin >> current;
		if (prev >= current) {
			length++;
		} else {
			max_length = max(max_length, length);
			length = 0;
		}
		prev = current;
	}
	max_length = max(max_length, length);
	cout << max_length << endl;
}

int main() { C(); }

