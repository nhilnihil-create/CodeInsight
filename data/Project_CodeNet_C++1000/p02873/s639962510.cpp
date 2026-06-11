#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
typedef long long int ll;
string S;
int main()
{
  ll i;
  ll sum=0;
  ll len, cl;
  ll last;

  cin >> S;

  len = S.size();
  last = 0;
  for (i=0; i<len; ) {
    cl=0;
    switch(S[i]) {
    case '<':
      while (S[i] == '<' && i<len) {cl++; i++;}
      sum += cl*(cl+1)/2;
      break;
    case '>':
      while (S[i] == '>' && i<len) {cl++;i++;}
      if (last <= cl) {
	sum += cl*(cl+1)/2 - last;
      } else {
	sum += cl*(cl-1)/2;
      }
      break;
    }
    last = cl;
//printf("%d %d\n", cl, sum);
  }

//  printf("%lld\n", sum);
  cout << sum << endl;
  return 0;
}
