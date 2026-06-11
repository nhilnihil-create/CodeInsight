#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    string N;
    cin >> N;
    int tmp=0;
 	for(int i=0;i<N.size();i++)
 		tmp+=N[i]-'0';
 	if(tmp%9==0)
 		cout<<"Yes";
 	else
 		cout<<"No";
 		
    return 0;
}