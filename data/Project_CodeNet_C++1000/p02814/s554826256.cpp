/*

                              Jai Shree Krishna !!
                                 Radhe Radhe !!
                                 
             उद्यमेन हि सिद्ध्यन्ति कार्याणि न मनोरथैः। नहि सुप्तस्य सिंहस्य मुखे प्रविशन्ति मृगाः।।
             
*/
   
   
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
typedef long long ll;
#define loop(i,n)  for(int i=0;i<n;i++)
#define read(a) int a; cin >>a;
#define readarr(a,n) int a[n] ; for(int i=0;i<n;i++) cin >> a[i];
#define readmat(a,n,m) int a[n][m]; for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define pi pair<int,int>
#define vvi vector<vector<int>>
#define sti set<int>
#define vpi vector<pair<int,int>>
#define print(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" "; cout<<endl;
#define printmat(a,n,m) for(int i=0;i<n;i++) {for(int j=0;j<m;j++) cout<<a[i][j]<<" "; cout<<endl;}
#define fast ios_base::sync_with_stdio(false);  cin.tie(NULL);
#define endl "\n"
#define mp make_pair
#define ins insert
#define rep(i,s,e)  for(int i=s;i<=e;i++)
#define repd(i,s,e)  for(int i=e;i>=s;i--)
#define vb vector<bool>
#define read2(n,m) int n,m; cin >> n >> m;
#define range(v) v.begin(),v.end()
#define sortd(v) sort(v.begin(),v.end(),greater<int>())
#define sorti(v) sort(v.begin(),v.end())

const ll inf = 1e18;
const ll mod = 1e9 + 7;
 
signed main()
{
 
    fast;
    read2(n,m);
    readarr(a,n);
    int k=0;
    int lcm = a[0]/2;
    sti v;
    rep(i,0,n-1) {
    	a[i]=a[i]/2;
    	int x=a[i];
    	k=0;
    	while(x%2==0){
    		 k++;
    		 x=x/2;
    	}
    	v.ins(k);
    	lcm = (lcm*a[i])/__gcd(a[i],lcm);
    }
    
    
    if(v.size()!=1) {
    	cout<<0<<endl;
    	return 0;
    }
    
    int i=1,ans=0;
    if(m<lcm) {
    	cout<<0<<endl;
    	return 0;
    }
    ans = m/lcm;
    ans = (ans+1)/2;
    cout<<ans<<endl;
    return 0;
}

/* Pooja Yadav */