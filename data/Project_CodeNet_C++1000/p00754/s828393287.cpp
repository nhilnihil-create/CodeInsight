#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<time.h>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define rp(a) while(a--)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
const double PI=acos(-1);
const double EPS=1e-10;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int main(){
	char d[4]={'[',']','(',')'};
	string s;
	while(getline(cin,s),s!="."){
		rep(i,s.size()){
			bool h=false;
			rep(j,4)if(s[i]==d[j])h=true;
			if(!h){
				s.erase(s.begin()+i);
				i--;
			}
		}
		while(1){
			int it;
			if((it=s.find("[]"))!=string::npos)s.erase(it,2);
			else if((it=s.find("()"))!=string::npos)s.erase(it,2);
			else break;
		}
		if(s=="")cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}