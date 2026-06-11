#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
  cin >> N;
  vector<int>a(N);
  int count = 0;
  for(int i = 0 ; i < N ; i++){
  		cin >> a.at(i);
    if(i%2==0&&a.at(i)%2==1)count++;
  }
  
  cout << count << endl;
}
