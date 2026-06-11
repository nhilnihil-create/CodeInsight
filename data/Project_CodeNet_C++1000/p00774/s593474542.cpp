#include "bits/stdc++.h"
#include <random>
#define REP(i,a,b) for(i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)
#define ll long long
#define ull unsigned ll
typedef long double ld;
#define SQR(X)  ( (X)*(X) )
#define CUBE(X) ( (X)*(X)*(X) )
#define ALL(a) (a).begin(),(a).end()
#define ifnot(a) if(not a)
#define dump(x)  cerr << #x << " = " << (x) << endl
using namespace std;
 
 
void reader(int &a){scanf("%d",&a);}
void reader(double &a){scanf("%lf",&a);}
void reader(char a[]){scanf("%s",a);}
void reader(ll &a){scanf("%lld",&a);}
void reader(ull &a){scanf("%llu",&a);}
// void reader(string& a){cin >> a;};
template<class T,class U> void reader(T& t,U& u){reader(t); reader(u);}
template<class T,class U,class V> void reader(T& t,U& u,V& v){reader(t); reader(u); reader(v);}
 
void writer(int a,char c) {printf("%d",a); putchar(c);}
void writer(ll a,char c) {printf("%lld",a); putchar(c);}
void writer(double a,char c) {printf("%.20lf",a); putchar(c);}
void writer(char a[]) {printf("%s",a);};
void writer(char a[],char c) {printf("%s",a);putchar(c);};
void writer(char a,char c) {putchar(a); putchar(c);};
template<class T>void writerLn(T t){writer(t,'\n');}
template<class T,class U>void writerLn(T t,U u){writer(t,' ');writer(u,'\n');}
template<class T,class U,class V> void writerLn(T t,U u,V v){writer(t,' ');writer(u,' ');writer(v,'\n');}
template<class T> void writerArr(T x[], int n){int i;if(!n){putchar('\n');return;}rep(i,n-1) writer(x[i],' ');writer(x[n-1],'\n');}
template<class T> void writerVec(vector<T> x){int n=x.size();int i;if(!n){putchar('\n');return;}rep(i,n-1) writer(x[i],' ');writer(x[n-1],'\n');}
 
vector<std::string> split(const std::string &str, char sep){std::vector<std::string> v;std::stringstream ss(str);std::string buffer;while(std::getline(ss,buffer,sep)){v.push_back(buffer);}return v;}
 
// #define int ll
bool test = false;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
ull mod = (int)1e9 + 7;
//..................
int H;
int a[10][6];
int cnt = 0;
void erace() {
  int i,j,k;
  rep(i,H) rep(j,3) {
	if(a[i][j] == -1) continue;
	if(a[i][j] == a[i][j+1] && a[i][j] == a[i][j+2]) {
	  int target = a[i][j];
	  REP(k,j,5) {
		if (a[i][k] == target) {
		  cnt += target; a[i][k] = -1;
		}
		else break;
	  }
	}
  }
  /*
  rep(i,H) {
	rep(j,5) {
	  printf("%d ",a[i][j]);
	}
	puts("");
  }
  */
}
signed main(){
  int i,j,k,l;
  while(1) {
	cnt = 0;
	cin >> H;
	if (H == 0) break;
	rep(i,H) rep(j,5) {
	  reader(a[i][j]);
	}
	bool is_continue = true;
	while(is_continue) {
	  erace();
	  is_continue = false;
	  rep(k,5) {
		for(i=H-1;i>-1;i--) {
		  if(a[i][k] != -1) continue;
		  for(j=i-1;j>-1;j--) {
			if(a[j][k] != -1) break;
		  }
		  if(j != -1) is_continue = true;
		  
		  a[i][k] = a[j][k];
		  a[j][k] = -1;
		}
	  }
	}
	cout << cnt << endl;
  }

  return 0;
}