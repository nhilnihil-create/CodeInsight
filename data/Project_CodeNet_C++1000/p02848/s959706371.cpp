#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int n,p; cin>>n; string str; cin>>str;
	string ptr="ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(int i=0;i<str.length();++i){
        for(int j=0;j<26;++j){
            if(ptr[j]==str[i]){p=j; break;}
        }
        str[i]=ptr[p+n];
	}
	cout<<str;
}
