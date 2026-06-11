#include "bits/stdc++.h"
using namespace std;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )

int main() {
	string t;
	cin >> t;
rep(i,0,t.size()){
  if (t.at(i)=='?'){
    t.at(i)='D';
  }
	}
cout<< t<<endl;
}
