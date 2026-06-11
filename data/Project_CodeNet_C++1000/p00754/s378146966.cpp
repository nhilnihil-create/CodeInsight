#include<bits/stdc++.h>

using namespace std;

int main(){
		string a;
		while(getline(cin,a) && a!="."){
				int n=a.length();
				int i;
				stack<int> st;
				for(i=0;i<n;i++){
						if(a[i]=='['){
								st.push(1);
						}else if(a[i]==']'){
								if(st.empty()==1){
										cout<<"no"<<endl;
										break;
								}
								if(st.top()==1){
										st.pop();
								}else{
										cout<<"no"<<endl;
										break;
								}
						}else if(a[i]=='('){
								st.push(2);
						}else if(a[i]==')'){
								if(st.empty()==1){
										cout<<"no"<<endl;
										break;
								}
								if(st.top()==2){
										st.pop();
								}else{
										cout<<"no"<<endl;
										break;
								}
						}
				}
				
				if(i==n && st.empty())cout<<"yes"<<endl;
				else if(i==n && !st.empty())cout<<"no"<<endl;
		}
		return 0;
}