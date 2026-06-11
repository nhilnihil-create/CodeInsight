#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define l long
#define pb push_back
#define mp make_pair
#define mt make_tuple
set <int> v[26];

int main() {
	// your code goes here
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    string s1,s2; cin>>s1>>s2;
    int l1=s1.length(), l2=s2.length();
    for(int i=0;i<l1;i++)
    {
        v[ s1[i] - 'a' ].insert(i);
    }
    ll c = 0, pos = 0;
    for(int i=0;i<l2;i++)
    {
        int j = s2[i] - 'a';
        if(v[j].empty()){ cout<<-1; return 0; } 
        auto it = v[j].lower_bound(pos);
        if( it == v[j].end() ){ c++; pos = 0; }
        pos = *v[j].lower_bound(pos);
        pos++;
    }
    cout<<(ll)c*l1 + pos;
	
	
	return 0;
}
