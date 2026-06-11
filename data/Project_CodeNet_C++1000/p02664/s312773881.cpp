#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fo(a,b) for(int a=0;a<b;a++)
#define Sort(a) sort(a.begin(),a.end())
#define rev(a) reverse(a.begin(),a.end())
#define fi first
#define se second
#define bgn begin()
#define sz size()
#define en end()
#define pb push_back
#define pp() pop_back()
#define V vector
#define P pair
#define yuko(a) setprecision(a)
#define uni(a) a.erase(unique(a.begin(),a.end()),a.end())
#define Q queue
#define pri priority_queue
#define Pri priority_queue<int,vector<int>,greater<int>>
#define PriP priority_queue<P<int,int>,vector<P<int,int>>,greater<P<int,int>>>
#define all(a)  (a).begin(),(a).end()
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second


signed main(){
  string t;
  cin >> t;
  int ans = 0;
  string a = "";
  fo(i,t.size()){
    if(t.substr(i , 2) == "PD"){
      a.pb('P');
      a.pb('D');
      i++;
    }
    else if(t[i] == 'D')
      a.pb('D');
    else if(t[i] == '?')
      a.pb('D');
    else if(t[i] == 'P')
      a.pb('P');
  }
  cout << a << endl;
}