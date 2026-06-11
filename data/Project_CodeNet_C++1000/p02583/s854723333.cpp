#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define Boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

void Crack() {
	long n,a;
    cin >> n;
    vector <long> A(n);
    for(int i=0;i<n;i++) cin >> A[i];
    long long ans = 0;
    sort(A.begin(),A.end());
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(int k=j+1;k<n;k++) {
                if(A[i]!=A[j] && A[i]!=A[k] && A[j]!=A[k] && A[i]+A[j]>A[k]) ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
	Boost;
    Crack();
	return 0;
}