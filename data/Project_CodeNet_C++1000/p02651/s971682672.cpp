#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<typename T>
bool check(const vector<T> &v, const int &MAX, T x){ //v[i]<2^MAX
    int n=v.size();
    vector<T> ret=v;
    int d=0;
    for(int k=MAX-1; k>=0; k--){
        int p=-1;
        for(int i=d; i<n; i++){
            if((ret[i]>>k)&1){
                p=i;
                break;
            }
        }
        if(p==-1) continue;
        swap(ret[d], ret[p]);
        for(int i=0; i<n; i++){
            if(i==d) continue;
            if((ret[i]>>k)&1) ret[i]^=ret[d];
        }
		if((x>>k)&1) x^=ret[d];
        d++;
    }
    if(x) return false;
	else return true;
}
int main()
{
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<ll> a(n);
		string s;
		for(int i=0; i<n; i++) cin>>a[i];
		cin>>s;
		reverse(s.begin(), s.end());
		reverse(a.begin(), a.end());
		if(s[0]=='1'){
			cout<<1<<endl;
			continue;
		}
		bool dame=0;
		vector<ll> v;
		for(int i=0; i<n; i++){
			if(s[i]=='1'){
				if(!check(v, 60, a[i])){
					dame=1; break;
				}
			}else{
				v.push_back(a[i]);
			}
		}
		if(!dame) cout<<0<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
