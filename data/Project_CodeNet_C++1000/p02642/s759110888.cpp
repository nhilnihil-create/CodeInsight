#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define pb push_back
bool isPrime(ll n) 
{ 
    
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
   
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
ll minthis(ll a, ll b){
if(a < b){
return a;
}
return b;
}
ll maxthis(ll a, ll b){
if(a > b){
return a;
}
return b;
}
int gcd(int a, int b){
    if( a<0 ) a = -a;
    if( b<0 ) b = -b;
    while( b!=0 ){
        a %= b;
        if( a==0 ) return b;
        b %= a;
    }
    return a;
}
 
int findLargestDivisor(int n) 
{ 
	int max = 1;
    for (int i = 2; i < n; i++) {        
        if(n %(i) == 0) { 
            max = i;
        } 
    }
    return max;     
} 
	 
 
ll power(ll x, ll y)  
{  
    ll temp;  
    if(y == 0)  
        return 1;  
    temp = power(x, y / 2);  
    if (y % 2 == 0)  
        return temp * temp;  
    else
    {  
        if(y > 0)  
            return x * temp * temp;  
        else
            return (temp * temp) / x;  
    }  
} 
bool sortbysec(const pair<int, int>& a, 
               const pair<int, int>& b) 
{ 
    return (a.second < b.second); 
} 
map<int,int> mp;
/*
 void printDivisors(int n) 
{ 
    // Note that this loop runs till square root 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                printf("%d ", i); 
  
            else // Otherwise print both 
                printf("%d %d ", i, n/i); 
        } 
    } 
} 
 */
bool check(int n){
	if(n == 1 && mp[1] > 1){
		return false;
	}
	else if(n == 1){
		return true;
	}
	 for (int i=1; i<=sqrt(n); i++){ 
         if (n%i == 0){ 
            if (n/i == i){ 
                if(mp[i]){
		       //cout << 1 << " " << mp[i] << " " << i << " " << i << "\n";	
		return false;}
	    }  
            else if((mp[i] || mp[n/i]) && n/i == n && (mp[n/i] > 1 || mp[i])){
                //cout << 2 << " " << mp[i] << " " << mp[n/i] << " " << i << " " << n/i << "\n"; 
		    return false;
	    }	
		else if((mp[i] || mp[n/i]) && n/i != n){
			
			//cout << 3 << " " << mp[i] << " " << mp[n/i] << " " << i << " " << n/i << "\n";
			return false;
		}
        } 
    }
	return true; 

}
void solve(){
	int n;
	cin >> n;
	vector<int> v;
	int ans = 0;
	for(int i = 0;  i < n ; i++){
		int x;
		cin >> x;
		mp[x]++;
		v.pb(x);
	}
	map<int,int>:: iterator it;
	for(auto x : v){
		if(check(x)) ans++;
	}
	cout << ans << "\n";
	
	
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--){
		solve();
	}
    return 0; 
}


