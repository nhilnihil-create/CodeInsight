#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// Container コンテナ型, map以外
template< template<class ...> class Ctn,class T>
std::ostream& operator<<(std::ostream& os,const Ctn<T>& v){
  auto itr=v.begin();
  while(itr!=v.end()){
    if(itr!=v.begin())cout << " ";
    cout << *(itr++);
  }
  return os;
}

int next(vector<vector<int>>& rsk,char c,int tmp){
  if(df)print(rsk[c-'a']);
  auto itr=
    upper_bound(rsk[c-'a'].begin(),rsk[c-'a'].end(),rsk[c-'a'][tmp]);
  if(itr==rsk[c-'a'].end()) return 0;
  if(df)print(itr-rsk[c-'a'].begin());
  return itr-rsk[c-'a'].begin();
}

int main(){
  string s,t; cin >>s >>t;
  int n=s.size();
  vector<vector<int>> rsk(26,vector<int>(s.size()+1,0));
  n=s.size();
  rep(i,n) rsk[s[i]-'a'][i+1]=1;
  rep(i,26)rep(j,n){
    rsk[i][j+1]+=rsk[i][j];
  }
  n=t.size();
  int tmp=0,m=0;
  rep(i,n){
    tmp=next(rsk,t[i],tmp);
    if(tmp==0){
      m++;
      tmp=next(rsk,t[i],tmp);
      if(tmp==0){
        if(df)print(t[i]);
        print(-1);
        return 0;
      }
    }
    
  }
  print((long int)m*s.size()+tmp);
}
