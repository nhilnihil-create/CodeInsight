#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
#include <numeric>
#include <iterator>
#include <math.h>
using namespace std;

int main(void){
  long N,K;
  cin >> N >> K;
  long R,S,P;
  cin >> R >> S >> P;
  string s;
  cin >> s;
  vector<long> ten;
  for(auto it = s.begin(); it != s.end(); it++){
    long tmp = 0;
    switch (*it)
    {
    case 'r':
      ten.push_back(P);
      break;
    case 's':
      ten.push_back(R);
      break;
    case 'p':
      ten.push_back(S);
      break;
    default:
      break;
    }
  }

  long tensum = accumulate(ten.begin(),ten.end(),0);
  for(long i =0; i < N - K; i++){
    if(s[i] == s[i+K]){
      tensum -= ten[i+K];
      s[i+K] = 0;
    }
  }
  cout << tensum << endl;
  return 0;
}