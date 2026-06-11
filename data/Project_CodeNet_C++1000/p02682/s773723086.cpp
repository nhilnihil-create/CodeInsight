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
	int A,B,C,K;
	cin>>A>>B>>C>>K;
	int ans=0;
	while(A!=0&&K!=0){
	  ans++;
	  A--;
	  K--;
	}
	
	while(B!=0&&K!=0){
	  B--;
	  K--;
	}
	
	while(C!=0&&K!=0){
	  ans--;
	  C--;
	  K--;
	}

    cout<<ans<<endl;
}

