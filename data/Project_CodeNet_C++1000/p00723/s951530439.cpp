#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<utility>
#include<cmath>
#include<set>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define pi acos(-1)
#define all(v) v.begin(),v.end()
using namespace std;

typedef pair<string,string> pss;

const double eps = 1e-8;
const double INF = 1e12;

string reverse(string s){
	string res="";
	rep(i,s.size()){
		res+=s[s.size()-i-1];
	}
	return res;
}


int main(){
	int n;
	string s;
	cin>>n;
	rep(k,n){
		set<string> st;
		cin>>s;
		vector<pss> vec;
		string left,right;
		loop(i,1,s.size()){
			left=right="";
			rep(j,s.size()){
				if(i<=j)right+=s[j];
				else left+=s[j];
			}
			vec.push_back(pss(left,right));
		}
		int size=vec.size();
		rep(i,size){
			vec.push_back(pss(vec[i].first,reverse(vec[i].second)));
			vec.push_back(pss(reverse(vec[i].first),vec[i].second));
			vec.push_back(pss(reverse(vec[i].first),reverse(vec[i].second)));
		}
		size=vec.size();
		rep(i,size){
			st.insert(vec[i].first+vec[i].second);
			st.insert(vec[i].second+vec[i].first);
		}
		cout<<st.size()<<endl;
	}
	return 0;
}