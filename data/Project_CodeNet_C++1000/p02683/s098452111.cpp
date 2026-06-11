#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)

int main(){
    int N,M,X;
    cin>>N>>M>>X;
    
    vector<int> C(N);
    vector<vector<int>> A(N,vector<int>(M));
    rep(i,N){
        cin>>C[i];
        rep(l,M){
            cin>>A[i][l];
        }
    }
    int ans=10000000;
    for(int i=0;i<(1<<N);i++){
        vector<int> skill(M);
        int sum=0;
        bitset<12>b(i);
        rep(j,N){
            if(b[j]){
             rep(l,M)skill[l]+=A[j][l];
             sum+=C[j];
            }
        }
        bool ok=true;
        rep(k,M){
         if(skill[k]<X){
          ok=false;
          break;
          }
        }  
        if(ok)ans=min(ans,sum);
        
    }
	if(ans==10000000){
	    cout<<-1<<endl;
	    return 0;}
	cout<<ans<<endl;
}

