#include<bits/stdc++.h>
using namespace std ; 
typedef long long ll;
#define forn(i,e) for(ll i=0; i<e; i++)
#define endl "\n"
#define zoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PB push_back 
#define MP make_pair
#define F first
#define S second


int main()
{

zoom;

string s ; cin >> s ; 
ll c ; c  =0  ;
forn(i , ((s.size()-1)/2) +1)
{
	if(s[i] != s[s.size()-1 - i])
	c++ ; 
}
cout << c ; 
}