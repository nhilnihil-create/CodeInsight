#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


vector<int> divisors(int n) {
    vector<int> result, aux;
    for (int i = 1; i*i <= n; ++i) 
        if (n % i == 0) {
            result.push_back(i);
            if (i*i != n) aux.push_back(n/i);
        }
    for (int i = aux.size()-1; i+1; --i) result.push_back(aux[i]);
    return result;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n; cin>>n;
	vector<int> a(n);
	map<int,int> cont;
	for(auto &x:a){
		cin>>x;
		cont[x]++;	
	}
	
	lint ans = n;
	
	
	
	
	for(int &x:a){
		vector<int> div = divisors(x);
		for(int &y:div){
			//cerr<<x<<" "<<y<<"\n";
			if((x != y && cont.count(y)) || (x==y && cont[y]>1)){ 
				ans--;
				break;
			}
		}
	
	}
	
	cout<<ans<<"\n";
	return 0;	
}
