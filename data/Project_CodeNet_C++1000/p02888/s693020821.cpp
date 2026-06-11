#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int N;
  	cin>>N;
  	int L[N];
  	rep(i,N) cin>>L[i];
  	sort(L,L+N);
  	int count=0;
  	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			for(int k=j+1;k<N;k++){
             	if(L[i]+L[j]>L[k]) count++; 
            }
        }
    }
  	
  	cout<<count<<endl;
}