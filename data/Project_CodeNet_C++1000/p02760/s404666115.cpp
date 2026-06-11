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


    int a[3][3],q,count=0,k=0,b;
    unordered_map<int,int> mp;
    for(int i=0; i<3; i++){
    	for(int j=0; j<3; j++){
    		cin>>a[i][j];
    	}
    }
    cin>>q;
    while(q--){
    	cin>>b;
    	mp.insert(make_pair(b,1));
    }
    for(int i=0; i<3; i++){
    	for(int j=0; j<3; j++){
    		if(mp.find(a[i][j])!=mp.end()){
    			count++;
    		}
    		if(mp.find(a[j][i])!=mp.end()){
    			k++;
    		}
    	}		
    	if(count==3||k==3){
    		cout<<"Yes"<<endl;
    		return 0;
    	}
    	count=0,k=0;
    }
    k=0;
    for(int i=0; i<3; i++){
    	if(mp.find(a[i][i])!=mp.end()){
    		k++;
    	}
    }
    if(k==3){
    	cout<<"Yes"<<endl;
    }else if(mp.find(a[0][2])!=mp.end() && mp.find(a[1][1])!=mp.end() && mp.find(a[2][0])!=mp.end()){

        cout<<"Yes"<<endl;
    }else{
    	cout<<"No"<<endl;
    }
    return 0;
  }