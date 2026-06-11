#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<utility>
#include<numeric>
#include<algorithm>
#include<bitset>
#include<complex>

using namespace std;

typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }
int in() { int x; scanf("%d", &x); return x; }

int kako[110];
string str;

void g(){
	int c;
	str="";
	while(c=getchar(),c<' ');
	while(c>=' '){
		str+=(char)c;
		c=getchar();
	}
}

int main() {
	while(g(),str[0]!='.'){
//cout<<str<<endl;
		int i;
		int k=0;
		string res="yes";
		for(i=0;i<str.size();i++){
			if(str[i]=='[')kako[k++]=1;
			else if(str[i]=='(')kako[k++]=2;
			else if(str[i]==']'){
				if(k==0||kako[k-1]!=1){
					res="no";
					break;
				}
				k--;
			}else if(str[i]==')'){
				if(k==0||kako[k-1]!=2){
					res="no";
					break;
				}
				k--;
			}
		}
		if(k!=0)res="no";
		cout<<res<<endl;
	}
	return 0;
}