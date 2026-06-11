#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();  
  
    // To store the number of replacement operations  
    int cc = 0; 
  
    for(int i=0;i<n/2;i++) 
    { 

        if(s[i]== s[n-i-1])  continue; 

        cc+= 1; 

        if(s[i]<s[n-i-1])  
            s[n-i-1]= s[i] ; 
        else
            s[i]= s[n-i-1] ; 
    }
    cout << cc << "\n";
	return 0;
}
