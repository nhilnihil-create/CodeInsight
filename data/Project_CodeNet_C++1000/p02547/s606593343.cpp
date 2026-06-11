
#include<bits/stdc++.h>

#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;



signed main(){

#ifndef ONLINE_JUDGE
	//freopen("in.txt" , "r" , stdin);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);
    
    int n;
    cin >> n;
    vi d1(n) , d2(n);
    fo(i , n){
        cin >> d1[i] >> d2[i];
    }
    bool ans = 0;
    fo(i , n - 2){
        bool ok = 1;
        ok &= d1[i] == d2[i];
        ok &= d1[i + 1] == d2[i + 1];
        ok &= d1[i + 2] == d2[i + 2];
        ans |= ok;
    }

    cout << (ans ? "Yes\n" : "No\n") ;

    return 0;

}

