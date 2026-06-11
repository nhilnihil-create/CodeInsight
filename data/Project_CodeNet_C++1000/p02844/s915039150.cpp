#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
 
  int ans = 0;
  for (int i=0; i<1000; i++) {
	string t(3,'0');
	for (int tmp=i,j=0; j<3; j++) t[j] = '0' + (tmp%10),tmp/=10;
     
	auto pos = -1;
    bool f = false;
    for (int i=0; i<3; i++) {
	  pos = s.find(t[i], pos+1);
      if (pos == string::npos)  break;
      if (i==2) f = true;
    }
    
    if (f) ans++;
  }
  
  cout << ans << endl;
}