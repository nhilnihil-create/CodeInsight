#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(void){
	string s;
	while(getline(cin,s),s!="."){
		vector<int> cnt;
		cnt.clear();
		for(int i = 0 ; i < s.size() ; i ++){
				if(s[i] == '[')
					cnt.push_back(1);	
				if(s[i] == ']'){
					if(cnt.size()==0){
						cnt.push_back(1);
						break;
					}
					if(cnt[cnt.size()-1] == 1)
						cnt.pop_back();
					else break;
				}
				
				if(s[i] == '(')
					cnt.push_back(2);
				if(s[i] == ')'){
					if(cnt.size()==0){
						cnt.push_back(2);
						break;
					}
					if(cnt[cnt.size()-1] == 2)
						cnt.pop_back();
					else break;
				}
//				cout<<s[i]<<" "<<sika<<" "<<maru;
		}
		if(cnt.size())
			cout<<"no";
		else 
			cout<<"yes";
		cout<<endl;
	}
} 