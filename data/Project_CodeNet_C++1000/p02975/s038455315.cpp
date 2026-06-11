#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define rept(i,a,b) for(int i=a; i<b; i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> P;
typedef map<int, int> mp;

const int MOD = 1e9 + 7;


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;
    cin >> n;
    vi a(n);
    vi all;
    mp cnt;

    rep(i, n){
        cin >> a[i];
        cnt[a[i]]++;
    }

    if(cnt[0] == n){
        cout << "Yes" << endl;
        return 0;
    }
    if(n % 3 != 0){
        cout << "No" << endl;
        return 0;
    }

    for(auto& p : cnt){
//        cout << p.first << " " << p.second << endl;
        rep(i, p.second * 3 / n){
            all.push_back(p.first);
        }
    }

//    for(auto& p : all) cout << p << " ";
//    cout << endl;

    if (all.size() == 3 && (all[0] ^ all[1] ^ all[2]) == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    } 
 
    return 0;
}

