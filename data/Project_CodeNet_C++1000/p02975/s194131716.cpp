#include<bits/stdc++.h>
using namespace std;

typedef long long llint;
typedef long double ld;

#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint> > que;
priority_queue<llint> Que;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve(){
    int n;
    cin >> n;
    vector<llint>a(n);
    for(int i=0;i<n;i++)cin >> a[i];
    sort(a.begin(),a.end());
    if(n%3){
        if(a[0]==0 && a[n-1]==0){
            cout << "Yes" << endl;
            return;
        }
        else{
            cout << "No" << endl;
            return;
        }
    }
	if(a[0]==a[n/3-1] && a[n/3]==a[n/3*2-1] && a[n/3*2]==a[n-1] && (a[0]^a[n/3]^a[n/3*2])==0){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
}

int main(){
  solve();
  return 0;
}
