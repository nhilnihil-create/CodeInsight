# include <algorithm>
# include <cassert>
# include <cctype>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <cmath>
# include <iostream>
# include <map>
# include <queue>
# include <set>
# include <sstream>
# include <stack>
# include <string>
# include <vector>
# include <iomanip>
 
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
# define irep(i, n) for (int i = int(n) - 1; i >= 0; i--)
# define FOR(i, m, n) for (int i = int(m); i < (int)(n); i++)
# define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
 
int main(){
  long n,len,priv,cur;
  vector<long> v;
  vector<long>::iterator low;
  len = 0;
  priv = -1;
  cin >> n;
  rep(i,n){
  	cin >> cur;
  	if(cur>priv){
  		v.push_back(cur);
  		len++;
  	}else{
  		low = lower_bound(v.begin(), v.end(), cur);
  		*low = cur;
  		//cout << *low << endl;
  	}
  	priv = *(v.end()-1);
	//cout << priv << endl;
  }
  /*for(auto itr=v.begin(); itr<v.end();itr++){
  	cout<< *itr << " ";
  }
  cout << endl;*/
  cout << len << endl;
}