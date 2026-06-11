#include <bits/stdc++.h>
using namespace std;

#define int long long



typedef long long ll;
typedef long double ld;






bool cmp(pair<int,int>& a,pair<int,int>& b){
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}








signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    cout<<t*t<<endl;
    return 0;
}