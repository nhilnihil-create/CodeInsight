#include<bits/stdc++.h>

using namespace std;


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

	  string s;
	  char v[2] = {'e','s'};

     cin >> s;

	 int len = s.size()-1;

     if(s[len]=='e')
      {
          s = s+v[1];
	  }
	 else if(s[len]=='s')
	 {
		 s = s+v[0]+v[1];
	 }
	 else
		 s = s+v[1];


	 cout << s ;
}
