#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> p;


int main(void){
	int n;
  cin >> n;
  vector<string> list;
  rep(i, n){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    list.push_back(s);
  //  cout << s << endl;
  }
  sort(list.begin(), list.end());
  //rep(i, n) cout << list.at(i) << endl;
  ll ans = 0, count = 1;
  int begin = 0, end = 1;
  
  
  
  while(end<n){
    string left = list.at(begin), right = list.at(end);
    if(left==right){
      count++;
      end++;
    }
    else {
      ans += (count*(count-1))/2; 
      begin=end; 
      end ++;
      count =1;
    }
    //cout << count << endl;
  
  }
  //cout << count << endl;
  ans += (count*(count-1))/2; 
  
  cout << ans;
}
