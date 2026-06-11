#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define VI vector<int>
#define PII pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db double
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x){return mrand()%x;}
clock_t ac; double TLE(){return (double)(clock()-ac)/CLOCKS_PER_SEC;}
void DBG() {cerr << "]" << endl;}
template<class H, class... T> void DBG(H h, T... t) {
cerr << to_string(h);
if(sizeof...(t)) cerr << ", ";
DBG(t...);}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
bool ispalingrome(string s){
 int n = sz(s);
 for(int i=0;i<n;i++){
   	if(s[i]!=s[n-i-1]){
	  return false;
	}
 }
 return true;
}
int main(){
 ios::sync_with_stdio(0);
 cin.tie(0);
 string s;
 cin>>s;
 int n = sz(s);
 if(ispalingrome(s)){
   string left="";
   string right="";
   for(int i=0;i<(n-1)/2;i++){
     left+=s[i];
   }
   for(int i=((n+3)/2)-1;i<n;i++){
     right+=s[i];
   }
   if(ispalingrome(left)&&ispalingrome(right)){
     cout<<"Yes\n";
   }
   else{
     cout<<"No\n";
   }
 }
 else{
  cout<<"No\n";
 }
}


