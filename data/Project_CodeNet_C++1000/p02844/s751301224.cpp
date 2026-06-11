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
	int d = to_string(i).size();
    string t(3-d, '0');
    t += to_string(i);

	std::string::size_type pos = -1;
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