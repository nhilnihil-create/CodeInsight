#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

int stoi(string s){
	int res=0;
	for(int i=s.size()-1;i>=0;i--){
		res+=(s[i]-'0')*pow(10,s.size()-1-i);
	}
	return res;
}

string itos(int x){
	int size=log10(x);
	string res="";
	for(int i=size;i>=0;i--){
		int sla=pow(10,i);
		res+=(char)(x/sla+'0');
		x%=(int)pow(10,i);
	}
	return res;
}

int main(){
	string a,na,pre;
	int l;
	while(cin>>a>>l){
		vector<int> vec;
		if(a=="0" && l==0)break;
		vec.push_back(stoi(a));
		pair<int,int> ans;
		rep(p,20){
			a=itos(vec[vec.size()-1]);
			ans.first=ans.second=-1;
			int size=a.size();
			if(a.size()<l){
				for(int i=0;i<l-size;i++){
					string alt='0'+a;
					a=alt;
				}
			}
			sort(a.begin(),a.end());
			int mini=stoi(a);
			string res="";
			for(int i=0;i<a.size();i++){
				res+=a[a.size()-1-i];
			}
			int maxi=stoi(res);
			na=itos(maxi-mini);
			rep(i,vec.size()){
				if(vec[i]==stoi(na)){
					ans.first=vec.size();
					ans.second=i;
					break;
				}
			}
			vec.push_back(stoi(na));
			if(ans.first!=-1)break;
		}
		cout<<ans.second<<" "<<vec[ans.first]<<" "<<ans.first-ans.second<<endl;
	}
	return 0;
}