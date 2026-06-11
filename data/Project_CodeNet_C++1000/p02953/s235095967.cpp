#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
#define MOD 1000000007
#define PI 3.141592653
using namespace std;

ll A[100001];
bool B[100001];

void solve(){
	int n; cin>>n;
	A[0] = -100;
	for(int i=1; i<=n ; i++) cin>>A[i];

	A[1]--;
	for(int i=2; i<=n; i++){
		if(A[i] < A[i-1]){
			cout<<"No";
			return;
		}
		else if(A[i] > A[i-1]){
			A[i]--;
		}
	}
	cout<<"Yes";
}

int main()
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(12);

    int t =1; //cin>>t;
    for(int i=1; i<=t; i++){
        solve();
        cout<<"\n";
    }
    return 0;

}