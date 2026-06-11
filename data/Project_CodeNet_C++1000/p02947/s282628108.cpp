#include <bits/stdc++.h>
using namespace std;

#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
int main(){
	long long N ,count = 0;
  cin >> N;
  vector<string> st(N);
  map<string,long long> str;
  froop1(0,N){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    st.at(i)= s;
    if(str.count(st.at(i))) str[st.at(i)]++;
    else str[st.at(i)] = 1;
  }
  for(pair<string,long long> p : str){
   long long k = p.second;
    long long c = 0;
    for(long long j = 2;j <= k;j++){
      if(j == 2)c++;
      else c += (j - 1);
    }
    count += c;
  }
  cout << count << endl; 
  return 0;
}