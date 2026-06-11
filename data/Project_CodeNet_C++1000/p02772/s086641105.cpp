#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>

//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
     ios_base::sync_with_stdio(false);cin.tie(NULL);
     int n;
     cin>>n;
     v A(n),B;
     for(auto &x:A)cin>>x;
     for(int i=0;i<n;i++){
		 if(A[i]%2==0){
			 B.push_back(A[i]);
			 }
		 }
		 int m=B.size(),c=0;
		 for(int j=0;j<m;j++){
			 if(B[j]%3==0 || B[j]%5==0){c++;}
			 else{continue;}
			 }
			 if(c==m){cout<<"APPROVED" <<"\n";}
			 else{cout<<"DENIED" <<"\n";}
}
