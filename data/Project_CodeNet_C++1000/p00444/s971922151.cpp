#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0;i < N;i++)

int main()
{
  int p[] = {500,100,50,10,5,1};
  int data;
  while(cin >> data,data){
    data = 1000 - data;
    int cnt = 0;
    Rep(i,6) {
      while(p[i] <= data) {
	data -= p[i];cnt++;
      }
    }
    cout << cnt << endl;
  }
  return 0;
}