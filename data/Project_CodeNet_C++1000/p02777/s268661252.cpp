#include <bits/stdc++.h>


using namespace std;


#define ll long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()


ll sum(int n);

void go(){
	string s,t;cin>>s>>t;
	int a,b;cin>>a>>b;
	string u;cin>>u;
	if(u==t) b--;
	if(u==s) a--;
	cout << a << " " << b;
}
int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

   go();

   return 0;
}

ll sum(int n){                
   if(n == 0){
      return n;
   }else{
      return sum(n/10) + n%10;
   }
}
