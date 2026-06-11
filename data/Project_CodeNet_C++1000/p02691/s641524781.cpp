#include <iostream>
typedef long long ll;
using namespace std;

int a[200010], cnt[200010]={};

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; ++i) cin >> a[i];
    ll ans=0;
    for(int i=N-1; i>=0; --i){
        if(i+a[i]<=N-2) ans += cnt[i+a[i]];
        if(i>a[i]) ++cnt[i-a[i]];
    }
    cout << ans << endl;
	return 0;
}
