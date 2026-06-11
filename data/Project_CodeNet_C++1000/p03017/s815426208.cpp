#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecbool vector<bool>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)


int main()
{
  ll n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  forll(i, b, d-1){
	if(s[i] == '#' && s[i + 1] == '#'){
	  cout << "No" << endl;
	  return 0;
	}
  }
  forll(i, a, c-1){
	if(s[i] == '#' && s[i + 1] == '#'){
	  cout << "No" << endl;
	  return 0;
	}
  }
  if (c > d){
	forll(i, b-2, d-1){
	  if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
		cout << "Yes" << endl;
		return 0;
	  }
	}
	cout << "No" << endl;
	return 0;
  }
  cout << "Yes" << endl;
}
