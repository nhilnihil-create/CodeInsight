#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vecs vector<string>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

int main()
{
  ll k=0;
  string s, prev, next;
  cin >> s;
  
  forll(i, 0, s.size()){
	forll(j, 0, 2){
	  next = s.substr(i, j + 1);
	  if (prev != next){
		k++;
		prev = next;
		i += j;
		break;
	  }
	}
  }	
  cout << k << endl;
}