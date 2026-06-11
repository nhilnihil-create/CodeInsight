#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	     //  #ifndef ONLINE_JUDGE
      //  // for getting input from input.txt
      //  freopen("input.txt", "r", stdin);
      //  // for writing output to output.txt
      //  freopen("output.txt", "w", stdout);
      // #endif
	string s;
	cin>>s;
	
	if(count(s.begin(),s.end(),s.at(0)) == 2 && count(s.begin(),s.end(),s.at(1)) == 2
		&& count(s.begin(),s.end(),s.at(2)) == 2 && count(s.begin(),s.end(),s.at(3)) == 2)
	{ cout<<"Yes"<<"\n"; return 0; }
	cout<<"No"<<"\n";
	return 0;
}