#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int>P;
typedef tuple<int,int,int,int>T;
#define PI 3.14159265359
#define MOD 1000000007
const int MAX =510000;
int main(){
  	int N,K;
  	cin >>N>>K;
  	string S;
  	cin >>S;
  	int red=0,blue=0;
  	int mae=0,usi=0;
  	if(S[0]=='L'){mae=1;}	
  	if(S[N-1]=='R'){usi=1;}
  	rep(i,N-1){
    	if(S[i]=='R'&&S[i+1]=='L')red++;
    	if(S[i]=='L'&&S[i+1]=='R')blue++;
    }
  	int unhappy=0;
  	if(K<red){unhappy=2*(red-K)+mae+usi;}
  	else if(K==red){
    	if(mae==0&&usi==0){unhappy=1;}
    	else{unhappy=mae+usi;}
    }
    else{
     	unhappy=1;
    }	
  	cout<<N-unhappy;
  
}
