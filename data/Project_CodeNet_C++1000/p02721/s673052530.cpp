#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
#define ALL(a) (a.begin()),(a.end())


int64_t N; 
int64_t K; 
int64_t C; 
vector<int> L;
vector<int> R;
string S;
int main() {
 
    cin>>N>>K>>C>>S; 

    
    for(int i=0; i<N; i++){
        if(S[i]=='o'){
            L.push_back(i);
            i=i+C;
        }
    }

    for(int i=N-1; i>=0; i--){
        if(S[i]=='o'){
            R.push_back(i);
            i=i-C;
        }
    }
    reverse((R.begin()),(R.end()));

    int64_t x=0;
    int64_t j=0;

    for(int i=0; i<N; i++){
        if(S[i]=='o'){
		    x=lower_bound((L.begin()),(L.end()),i)-L.begin();
		    j=lower_bound(ALL(R),i+1)-R.begin();
    		j=R.size()-j;
	    	if(x+j<K) cout<<i+1<<endl;	
        }
    }

    return 0;
}
