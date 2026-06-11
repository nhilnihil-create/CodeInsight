#include<iostream>
#include<string>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
using namespace std;

bool check(string s){
	bool res=true;
	rep(i,s.size()){
		if(s[i]=='('){
			int cnt[2]={0,0};
			bool con=false;
			loop(j,i+1,s.size()){
				if(cnt[0]==0 && cnt[1]==0 && s[j]==')'){
					string next=s.substr(i+1,j-i-1);
					i=j;
					if(!check(next))return false;
					con=true;
					break;
				}else if(s[j]=='(')cnt[0]++;
				else if(s[j]==')')cnt[0]--;
				else if(s[j]=='[')cnt[1]++;
				else if(s[j]==']')cnt[1]--;
			}
			res&=con;
		}else if(s[i]=='['){
			int cnt[2]={0,0};
			bool con=false;
			loop(j,i+1,s.size()){
				if(cnt[0]==0 && cnt[1]==0 && s[j]==']'){
					string next=s.substr(i+1,j-i-1);
					i=j;
					if(!check(next))return false;
					con=true;
					break;
				}else if(s[j]=='(')cnt[0]++;
				else if(s[j]==')')cnt[0]--;
				else if(s[j]=='[')cnt[1]++;
				else if(s[j]==']')cnt[1]--;
			}
			res&=con;
		}else if(s[i]==')')return false;
		else if(s[i]==']')return false;
	}
	return res;
}

int main(){
	string s;
	while(1){
		getline(cin,s);
		if(s==".")break;
		if(check(s))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}	
	return 0;
}