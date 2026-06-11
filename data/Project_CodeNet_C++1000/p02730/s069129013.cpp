#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vlli vector<ll>
#define vi vector<int>
#define vs vector<string>
#define vplli vector< pair< ll,ll> >
#define plli pair< ll,ll >
#define vps vector< pair< string, string> >
#define vpi vector< pair< int, int> >
#define all(x) x.begin(), x.end()
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define forn(i,n) for(ll i=0;i<n;i++)
#define print(arr,a,n) for(ll i=(a);i<(n);i++)cout<<(arr)[i]<<" ";
bool isp(string s){
 string ss = s;
  reverse(ss.begin(), ss.end());
  return (s == ss);
}
int main(){
    
       string s, a = "", b = "";
      cin >> s;
      int n = s.size(), i;
      for(i = 0; i < (n - 1)/2; i++){
        a+=s[i];
      }
      for(i = (n + 1)/2; i < n; i++){
        b+=s[i];
      }

      if(isp(a) && isp(b) && isp(s)){
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    
}