#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool fin(vector<string>a,string b){
	for(int i=0;i<a.size();i++)if(a[i]==b)return true;
	return false;
}
int main(){
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		string s;
		vector<string>anss(0);
		cin>>s;
		for(int i=0;i<s.size();i++){
			string t1,t2,t3,t4,t5,t6,t7,t8,a,b;
			a=s.substr(0,i);
			b=s.substr(i,s.size()-i);
			t1=a+b;
			t5=b+a;
			reverse(a.begin(),a.end());
			t2=a+b;
			t6=b+a;
			reverse(b.begin(),b.end());
			t3=a+b;
			t7=b+a;
			reverse(a.begin(),a.end());
			t4=a+b;
			t8=b+a;
			if(fin(anss,t1)==false)anss.push_back(t1);
			if(fin(anss,t2)==false)anss.push_back(t2);
			if(fin(anss,t3)==false)anss.push_back(t3);
			if(fin(anss,t4)==false)anss.push_back(t4);
			if(fin(anss,t5)==false)anss.push_back(t5);
			if(fin(anss,t6)==false)anss.push_back(t6);
			if(fin(anss,t7)==false)anss.push_back(t7);
			if(fin(anss,t8)==false)anss.push_back(t8);
		}
		cout<<anss.size()<<endl;
	}
	return 0;
}