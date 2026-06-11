#include <iostream>

using namespace std;

typedef long long ll;


int main() {
  ll t1,t2;
  ll a1,a2,b1,b2;
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;

  if(t1*a1 < t1*b1) {
    swap(a1,b1);
    swap(a2,b2);
  }
  

  ll tmp1 = t1*a1-t1*b1;
			  
  ll tmp2 = t1*a1+t2*a2-(t1*b1+t2*b2);
  if(tmp2 == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  else if (tmp2 > 0) {
    cout << 0 << endl;
    return 0;
  }

  if((tmp1 % (-tmp2)) == 0) {
      cout << (tmp1 / -tmp2) * 2 << endl;
    }
    else {
      cout << (tmp1 / -tmp2) * 2 + 1 << endl;
    }
}
