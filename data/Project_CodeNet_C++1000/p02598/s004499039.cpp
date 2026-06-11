#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long int lli;

lli bs(lli l, lli r, const vector<lli> &logs, const lli K){
	if (l>r) return l;
    lli mid = (l+r)/2;
    lli k = K;
    for (int i = 0; i < logs.size(); i++){
    	lli x = 0;
    	if (logs[i]>mid){
    		if ((logs[i]%mid)==0) x = logs[i]/mid -1;
    		else x = logs[i]/mid;
    		k-=x;
    		if (k<0) return bs(mid+1, r, logs, K);
    	}
    }
    if (k>=0) return bs(l, mid-1, logs, K);
}

int main(){
//	while(cin){
		
    int N = 0;
    lli K = 0;
    lli Ai = 0;
    lli sum = 0;
    lli max = 0;
    vector<lli> logs;
    cin >> N >> K;
    while(N--){
        cin >> Ai;
        logs.push_back(Ai);   
        sum += Ai;     
        if (Ai>max) max = Ai;
    }
    N = logs.size();
    lli min_possible = 0;
    lli max_possible = 0;
    
    if (N>1) min_possible = ceil(sum/(K+N-1));
    
    else if (K>0) min_possible = ceil(sum/(K+1));
    
    else min_possible = sum;
    
    if (min_possible>max) min_possible = max;
    if (min_possible==0) min_possible = 1;
    max_possible = max;
//	cout << "sum: " << sum << "   " << "min_possible: " << min_possible << "   max_possible: " << max_possible << endl;
    
    cout << bs(min_possible, max_possible, logs, K) << endl;
//}
    return 0;
}