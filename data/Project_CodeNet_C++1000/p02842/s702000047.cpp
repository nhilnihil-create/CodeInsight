#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int wari = n / 1.08;
  int wariwari = n / 1.08 + 1;
  int wada = wari * 1.08;
  int wadawada = wariwari * 1.08;
  
  queue<int> q;
  if(n == wada)q.push(wari);
  if(n == wadawada)q.push(wariwari);
  
  if(q.size() == 0)cout << ":(" << endl;
  else cout << q.front() << endl;
}