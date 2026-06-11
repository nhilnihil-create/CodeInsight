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
     int n,k;
     cin>>n>>k;
     v A,B;
     while(n!=0){
		 A.push_back(n%k);
		 n=n/k;
		 }
		 int m=A.size();
		 cout<<m <<"\n";
}
