#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<complex>
#include<stack>
using namespace std ;
typedef vector<int> vi ;
typedef vector<vi> vvi ;
typedef vector<string> vs ;
typedef pair<int, int> pii; 
typedef long long ll ;

#define loop(i,a,b) for(int i = a ; i < b ; i ++)
#define rep(i,a) loop(i,0,a)
#define all(a) (a).begin(),(a).end()

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(void){
  stack<int> st1;
  stack<int> st2;
  
  int n ;
  cin>>n;
  bool ans;
  rep(j,n){
    ans = false;
    st1.push(0);
    st2.push(0);
    rep(i,10){
      int inp;
      
      cin>>inp;

      if(st1.top()<inp){
	st1.push(inp);
      }else if(st2.top()<inp){
	st2.push(inp);
      }else{
	ans= true;
      }

    }
  if(!ans)cout<<"YES";
  else cout<<"NO";
  cout<<endl;
  }

}