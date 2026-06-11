    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i,n) for(int i=0; i<(n); i++)
    #define MAX_SIZE 1000005

    int main(){
    	int N;
    	cin >> N;
    	vector<int> A(N);
    	rep(i,N) cin >> A[i];
    	sort(A.begin(),A.end());
    	vector<bool> check(MAX_SIZE,true);
     
    	for(int i=0; i<N; i++){
    		if(!check[A[i]]) continue;
    		if(i!=N-1 && A[i]==A[i+1]){ check[A[i]]=false; }

    		for(int j=2; j*A[i]<=MAX_SIZE; j++){
    			check[j*A[i]] = false;
    		}
    	}

    	int ans=0;
    	for(int u : A){
    		if(check[u]){ ans++; }
    	}

    	cout << ans << endl;
    	return 0;
     
    }