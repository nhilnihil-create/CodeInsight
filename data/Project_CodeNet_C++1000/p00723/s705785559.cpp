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
  int m;

  cin >> m;

  while( m-- ) {
    string s;
    set<string> all;

    cin >> s;
    
    all.insert( s );
    
    for(int i=1; i<s.size(); i++) {
      string s1 = "", s1_ = "", s2 = "", s2_ = "";

      for(int j=0; j<i; j++) s1 += s[j], s1_ += s[i-1-j];
      for(int j=i; j<s.size(); j++) s2 += s[j], s2_ += s[s.size()-1-j+i];

      //cout << s1 + " "<< s1_ + " " << s2 + " " << s2_ << endl; 
      all.insert( s1 + s2_ );
      all.insert( s1_ + s2 );
      all.insert( s1_ + s2_ );
      all.insert( s2 + s1 );
      all.insert( s2 + s1_ );
      all.insert( s2_ + s1 );
      all.insert( s2_ + s1_ );
      
    }

    cout << all.size() << endl;
  }
  
}