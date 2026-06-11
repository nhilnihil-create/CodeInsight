#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int K;
  cin >> K;
  vector<int> a(32);
  a.at(0)=1;
  a.at(1)=1;
  a.at(2)=1;
  a.at(3)=2;
  a.at(4)=1;
  a.at(5)=2;
  a.at(6)=1;
  a.at(7)=5;
  a.at(8)=2;
  a.at(9)=2;
  a.at(10)=1;
  a.at(11)=5;
  a.at(12)=1;
  a.at(13)=2;
  a.at(14)=1;
  a.at(15)=14;
  a.at(16)=1;
  a.at(17)=5;
  a.at(18)=1;
  a.at(19)=5;
  a.at(20)=2;
  a.at(21)=2;
  a.at(22)=1;
  a.at(23)=15;
  a.at(24)=2;
  a.at(25)=2;
  a.at(26)=5;
  a.at(27)=4;
  a.at(28)=1;
  a.at(29)=4;
  a.at(30)=1;
  a.at(31)=51;
  cout << a.at(K-1) << endl;
}