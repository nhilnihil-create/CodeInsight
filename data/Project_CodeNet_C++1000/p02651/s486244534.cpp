#include<iostream>
#include<bitset>
#include<vector>
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

int ord(bitset<64> a){
  li i=1;
  bitset<64> b;
  while((b=(a>>i))!=bitset<64>(0)){
    a|=b;
    i*=2;
  }
  return a.count();
}

int in(bitset<64> a,vector<bitset<64>>& space){
  for(bitset<64> x:space){
    if(ord(x)==ord(a)) a^=x;
  }
  
  return a==bitset<64>(0);
}

void normarize(vector<bitset<64>>& space){
  int n=space.size();
  rep(k,n){
    int i=n-1-k;
    rep(j,i){
      if(ord(space[i]&space[j])==ord(space[i])) space[j]^=space[i];
    }
  }
}

void add(bitset<64> a,vector<bitset<64>>& space){
  if(df)print("add",a);
  for(bitset<64>& x:space){
    if(ord(x)==ord(a)) a^=x;
    if(ord(x)<ord(a)) swap(a,x);
  }
  if(ord(a)){
    space.push_back(a);
    normarize(space);
  }
  if(df)print(space);
}

int main(){
  int q;cin >>q;
  if(df)print(q);
  //  if(df)rep(i,20)print(i,ord(i));
  rep(_,q){
    int n; cin >>n;
    vector<bitset<64>> a(n);
    rep(i,n){
      li t;
      cin >>t;a[i]=t;
    }
    if(df)print("a",a);
    string s; cin >>s;
    vector<bitset<64>> space;
    int flag=0;
    rep(j,n){
      int i=n-j-1;
      int c=s[i]-'0'; bitset<64> h=a[i];
      if(df)print("c,h",c,h);
      if(c){
        if(!in(h,space)){
          flag=1;
          break;
        }
      } else {
        add(h,space);
      }
    }
    print(flag);
    if(df)print("---------------");
  }
}
