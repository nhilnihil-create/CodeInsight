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
    ll N,M;
    cin>>N>>M;
    int a;
    rep(i,M){
      cin>>a;
      N-=a;
    }
 if(0<=N)cout<<N<<endl;
  else cout<<-1<<endl;
}

