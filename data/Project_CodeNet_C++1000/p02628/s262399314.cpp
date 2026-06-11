    #include<bits/stdc++.h>
    #define lint long long
    #define st first
    #define nd second
    #define INF 0x3f3f3f3f
     
    using namespace std;
     
     
    int main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL); cout.tie(NULL);
    	int k, n;
    	cin>>n>>k;
    	vector<int> v(n);
    	for(int &x:v)cin>>x;
    	sort(v.begin(), v.end());
    	int s = 0;
    	for(int i=0;i<min(n,k);i++){
    		s += v[i];
    		//cerr<<v[i]<<"\n";
    	}
    	cout<<s<<"\n";
    	
    	return 0;	
    }