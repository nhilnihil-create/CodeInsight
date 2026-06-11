#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N,K,Dr,Ds,Dp;
  cin >> N >> K >> Dr >> Ds >> Dp;
	char c;
  vector<string>zyan(N);
        // そのうち一文字ずつ入れないといけなくなる！  
for (int i = 0; i < N; i ++) {
    cin >> c; 
      zyan.at(i) = c;
  }
int i =  0,answer = 0;
  for (i = 0; i < K; i ++) {
    if (zyan.at(i) == "r") {
    answer += Dp;
    }
    else if (zyan.at(i) == "s") {
      answer += Dr;
    }
    else if (zyan.at(i) == "p") {
      answer += Ds;
    }
  }
 for (; i < N; i ++) {
   if (zyan.at(i - K) != zyan.at(i)) {
 if (zyan.at(i) == "r" || zyan.at(i) == "saikyou") {
    answer += Dp;
    }
    else if (zyan.at(i) == "s" || zyan.at(i) == "saikyou") {
      answer += Dr;
    }
    else if (zyan.at(i) == "p" || zyan.at(i) == "saikyou") {
      answer += Ds;
    }
   }
 else {
  zyan.at(i) = "saikyou"; 
 }
 }
cout << answer << endl;
}