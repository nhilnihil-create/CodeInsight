/******************************************
* AUTHOR : GURUTEJA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define N 100005
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

void debug(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 

}

  int main() {
    debug();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     long long int n,k;

     cin>>n>>k;

     if(n>=k){
      	if(n%k==0){
      		cout<<0<<endl;
      	}else{
     	   cout<<k-(n%k)<<endl;
     	}
     }else{
     	if(n<=(k/2)){
     		cout<<n<<endl;
     	}else{
     		cout<<k-n<<endl;
     	}
     }

    return 0;
  }