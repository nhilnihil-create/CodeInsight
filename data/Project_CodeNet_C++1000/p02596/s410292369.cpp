#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#define vi vector<int>
#define lli long long int
#define fo(i,n) for(int i=1;i<=n;i++)
#define foo(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second
#define pb push_back
#define vii vector<lli>

#define ok ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#define vp vector<pair<lli,lli>>
#include <map>           
lli mod=1000000007;      

//vi r(300003),c(300003);   
vi a(1000009);

int main(){
   lli k;
   cin>>k;
   a[0]=7%k;
   fo(i,k){
   	a[i]=(a[i-1]*10+7)%k;
   }
   
   foo(i,k){
   	if(a[i]==0){
   		cout<<i+1;
   		return 0;
	   }
   }
   cout<<"-1";
}


