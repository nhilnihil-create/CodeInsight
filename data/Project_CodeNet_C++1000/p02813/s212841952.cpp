//coded b vishal mourya - the legendary coder
#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define f(a,b) for(ll i = a ; i < b ; i++ )
#define fj(a,b) for(ll j = a ; j < b ; j++ )
#define fk(a,b) for(ll k = a ; k < b ; k++ )
#define fasthoja ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<string> v;
void permute(string a, int l, int r) 
{ 
	// Base case 
	if (l == r) {
	    v.push_back(a);
	   // cout << v[v.size()-1] << "\n";
// 		cout<<a<<endl; 
	}
	else
	{ 
		// Permutations made 
		for (int i = l; i <= r; i++) 
		{ 

			// Swapping done 
			swap(a[l], a[i]); 

			// Recursion called 
			permute(a, l+1, r ); 

			//backtrack 
			swap(a[l], a[i]); 
		} 
	} 
}

int main(void){
    fasthoja;
    ll n; cin >> n;
    // cout << n << "\n";
    string sn = "";
    f(1,n+1) sn += to_string(i);
    // cout << sn <<"\n";
    
    vec p(n), q(n);
    string tp = ""; 
    string tq = "";
    f(0,n) cin >> p[i],tp += to_string(p[i]);
    f(0,n) cin >> q[i],tq += to_string(q[i]);
    
    // vector<string> v;
    string str = to_string(n);
    // cout << "sn : " << sn << "\n";
    permute(sn , 0 , sn.length() - 1);
    
    sort( v.begin() , v.end() );
    
    // cout << "yeh sort hai : \n";
    // f(0,v.size()) cout << v[i] << "\n";
    
    ll i1 = 0, i2 = 0;
    f(0,v.size()) {
        if( v[i] == tp ) i1 = i;
        
        if( v[i] == tq ) i2 = i;
    }
    
    cout << abs(i1 - i2) << "\n";
    
    
 return 0;
}
