#include<bits/stdc++.h>
#include<math.h>
using namespace std;


#define int long long
#define pb push_back
#define pii pair<int,int>
#define ppii pair<pii,pii>
#define mp  make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i=a; i<=b;i++)
#define F first 
#define S second
#define ccM 1000000007

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int32_t main()
{
	fastio;
    ios::sync_with_stdio(0);
 #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
 #endif
    int n;
   string s;

   cin >> s;

   if(s[2]==s[3] && s[4]==s[5]){

    cout << "Yes" << " ";
   }
   else{
    cout << "No";
}
return 0;
}

