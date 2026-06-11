#include <iostream>
#include <algorithm>
#include <vector>
#include<cmath>
using namespace std;
#define ll (long long)
#define PI (acos(-1))

int main()
{
int N;
string S;
cin >> N;
cin >> S;
int num=0;
char c1,c2,c3;

for(int i=0; i<N; i++){
  c1 = S[i];
  c2 = S[i+1];
  c3 = S[i+2];

  if(c1 =='A' && c2 == 'B' && c3 == 'C'){
    num++;
    i+=2;
  }
}

cout << num;
}
