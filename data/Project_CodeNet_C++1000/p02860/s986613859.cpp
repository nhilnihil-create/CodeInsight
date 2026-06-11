#include<bits/stdc++.h>
using namespace std;
int main(){
string s;int n;
while(cin>>n>>s){

if(n%2!=0){cout<<"No"<<endl;continue;}
int i,j;
j=n/2;
int k=j;
bool fl=false;
for(i=0;i<k;i++,j++){
if(s[i]!=s[j])fl=true;

}

if(fl){cout<<"No"<<endl;}
else cout<<"Yes"<<endl;



}

	return 0;
}