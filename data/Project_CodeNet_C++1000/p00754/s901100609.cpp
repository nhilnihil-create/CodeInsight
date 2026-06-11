#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define pf push_front 
#define mp make_pair
#define fr first
#define sc second
#define Rep(i,n) for(int i=0;i<(n);i++)
#define All(v) v.begin(),v.end()
typedef pair<int, int> Pii; typedef pair<int, Pii> Pip;
const int INF = 1107110711071107;


main()
{
  string s;
  while( 1 ) {
    getline( cin, s );
    if( s == "." ) break;

    stack<bool> st;
    bool flag = true;
    for(int i=0; i<s.size(); i++) {
      if( s[i] == '(' ) st.push( true );
      if( s[i] == '[' ) st.push( false );
      if( s[i] == ')' ) {
	if( st.size() == 0 ) {flag = false; break;}
	bool tmp = st.top(); st.pop();
	if( !tmp ) {flag = false; break;}  
      }
      if( s[i] == ']' ) {
	if( st.size() == 0 ) {flag = false; break;}
	bool tmp = st.top(); st.pop();
	if( tmp ) {flag = false; break;}  
      }
    }

    if( flag && st.size() == 0 ) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}