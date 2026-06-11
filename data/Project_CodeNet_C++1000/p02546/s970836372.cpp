#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <array>
using namespace std;
typedef long long unsigned int ll;
  
int main(){
string a;
 cin >> a;
 //cout << a.length() << endl;
 //cout << a[a.length()-1] << endl;
 if(a[a.length()-1] == 's'){
     a.append("es");
 }else{
     a.append("s");
 }
 cout << a << endl;
}
